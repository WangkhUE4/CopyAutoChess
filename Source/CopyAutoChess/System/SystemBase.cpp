#include "SystemBase.h"


SystemBase::SystemBase(const FString& sysName)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("ESystemName"), true);
	auto value = enumPtr->GetValueByName(FName(*sysName));
	checkf(value != INDEX_NONE, TEXT("系统的名字不匹配"));
	m_priority = value;
	m_name = sysName;
}

SystemBase::~SystemBase()
{

}

const FString& SystemBase::getSystemName() const
{
	return m_name;
}

int32 SystemBase::getPriority() const
{
	return m_priority;
}
