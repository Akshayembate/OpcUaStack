#include "OpcUaStackCore/ServiceSet/ReferenceTypeAttributes.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ReferenceTypeAttributes
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ReferenceTypeAttributes::ReferenceTypeAttributes(void)
		: ExtensibleParameterBase(),
		specifiedAttributes_(),
		displayName_(OpcUaLocalizedText::construct()),
		description_(OpcUaLocalizedText::construct()),
		isAbstract_(false),
		inverseName_(OpcUaLocalizedText::construct()),
		symmetric_(false),
		writeMask_(),
		userWriteMask_()
	{
		specifiedAttributes_ |= SpecifiedAttributes_Description;
		specifiedAttributes_ |= SpecifiedAttributes_DisplayName;
		specifiedAttributes_ |= SpecifiedAttributes_IsAbstract;
		specifiedAttributes_ |= SpecifiedAttributes_Symmetric;
		specifiedAttributes_ |= SpecifiedAttributes_InverseName;
		specifiedAttributes_ |= SpecifiedAttributes_WriteMask;
		specifiedAttributes_ |= SpecifiedAttributes_UserWriteMask;
	}

	ReferenceTypeAttributes::~ReferenceTypeAttributes(void)
	{
	}

	 OpcUaUInt32
     ReferenceTypeAttributes::specifiedAttributes(void) const
	 {
		 return specifiedAttributes_;
	 }

	void
	ReferenceTypeAttributes::displayName(
		const OpcUaLocalizedText::SPtr displayNameSPtr)
	{
		displayName_ = displayNameSPtr;		
	}

    OpcUaLocalizedText::SPtr
	ReferenceTypeAttributes::displayName(void) const
	{
		return displayName_;
	}

	void
	ReferenceTypeAttributes::description(
		const OpcUaLocalizedText::SPtr descriptionSPtr)
	{
		description_ = descriptionSPtr;
	}

    OpcUaLocalizedText::SPtr
	ReferenceTypeAttributes::description(void) const
	{
		return description_;
	}

	void ReferenceTypeAttributes::isAbstract(
		const OpcUaBoolean isAbstract)
	{
		isAbstract_ = isAbstract;
	}

    OpcUaBoolean
	ReferenceTypeAttributes::isAbstract(void) const
	{
		return isAbstract_;
	}

	void ReferenceTypeAttributes::symmetric(
		const OpcUaBoolean symmetric)
	{
		symmetric_ = symmetric;
	}

    OpcUaBoolean
	ReferenceTypeAttributes::symmetric(void) const
	{
		return symmetric_;
	}

	
	void
	ReferenceTypeAttributes::inverseName(
		const OpcUaLocalizedText::SPtr inverseNameSPtr)
	{
		inverseName_ = inverseNameSPtr;		
	}

    OpcUaLocalizedText::SPtr
	ReferenceTypeAttributes::inverseName(void) const
	{
		return inverseName_;
	}


	void ReferenceTypeAttributes::writeMask(
		const WriteableAttribute writeMask)
	{
		writeMask_ |= writeMask;
	}

    OpcUaUInt32
	ReferenceTypeAttributes::writeMask(void) const
	{
		return writeMask_;
	}

	
	void ReferenceTypeAttributes::userWriteMask(
		const WriteableAttribute userWriteMask)
	{
		userWriteMask_ |= userWriteMask;
	}

    OpcUaUInt32
	ReferenceTypeAttributes::userWriteMask(void) const
	{
		return userWriteMask_;
	}

	ExtensibleParameterBase::BSPtr 
	ReferenceTypeAttributes::factory(void)
	{
		return ReferenceTypeAttributes::construct();
	}
			
	void 
	ReferenceTypeAttributes::opcUaBinaryEncode(
		std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, specifiedAttributes_);
		displayName_->opcUaBinaryEncode(os);
		description_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, isAbstract_);
		OpcUaNumber::opcUaBinaryEncode(os, symmetric_);
		inverseName_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, writeMask_);
		OpcUaNumber::opcUaBinaryEncode(os, userWriteMask_);
	}
	
	void 
	ReferenceTypeAttributes::opcUaBinaryDecode(
		std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, specifiedAttributes_);
		displayName_->opcUaBinaryDecode(is);
		description_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, isAbstract_);
		OpcUaNumber::opcUaBinaryDecode(is, symmetric_);
		inverseName_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, writeMask_);		
		OpcUaNumber::opcUaBinaryDecode(is, userWriteMask_);
	}

}