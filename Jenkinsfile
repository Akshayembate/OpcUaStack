pipeline {
  agent any
  stages {
    stage('cppcheck') {
      steps {
        sh 'cppcheck --xml --xml-version=2 ./src 2> cppcheck.xml'
      }
    }

    stage('build_linux') {
      steps {
        sh 'docker-compose build'
        sh 'docker-compose run stack sh build.sh -t tst -j 4 -B Release --test-with-server opc.tcp://demo_server:8889'
      }
    }

    stage('test_linux') {
      steps {
        sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackCoreTest --log_format=XML --log_sink=core_results.xml --log_level=all --report_level=no'
        sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackServerTest --log_format=XML --log_sink=server_results.xml --log_level=all --report_level=no'
        sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackClientTest --log_format=XML --log_sink=client_results.xml --log_level=all --report_level=no'
      }
    }

    stage('build_windows') {
      steps {
        sh 'vagrant up'
        sh 'vagrant powershell -c "C:\\build_vs.bat -t local -B Release -vs \\"Visual Studio 15 2017 Win64\\""'
        sh 'vagrant powershell -c "C:\\build_vs.bat -t tst -B Release -vs \\"Visual Studio 15 2017 Win64\\""'
      }
    }
  }

  post {
    always {
      sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack cat core_results.xml > core_results.xml'
      sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack cat server_results.xml > server_results.xml'
      sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack cat client_results.xml > client_results.xml'
      xunit (
        thresholds: [ skipped(failureThreshold: '0'), failed(failureThreshold: '0') ],
        tools: [ BoostTest(pattern: '*_results.xml') ])

      sh 'docker-compose down --volumes'
      sh 'vagrant halt'
    }
  }
}
