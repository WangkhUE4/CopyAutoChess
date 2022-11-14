#include "Sys.h"
#include "GoodsSys/GoodsSystem.h"


void Sys::onCreateSys()
{
	UE_LOG(LogCopyAutoChess, Log, TEXT("创建系统..."));

	this->createSystem<GoodsSystem>();
}

struct Sys::Imp
{
private:
	std::vector<TSharedPtr<SystemBase>> m_systemArrary;
	std::vector<TWeakPtr<SystemBase>> m_needTickArr;
public:

	Imp()
	{
		const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("ESystemName"), true);
		const int32 max = enumPtr->GetMaxEnumValue();
		m_systemArrary.resize(max, TSharedPtr<SystemBase>());
	}

	void addSystem(const TSharedPtr<SystemBase>& sys, const FString& name)
	{
		const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("ESystemName"), true);
		uint8 value = enumPtr->GetValueByNameString(name);
		const bool checkOK = (int32)value < (int32)m_systemArrary.size();
		ensureMsgf(checkOK, TEXT("addSystem Error, index out of bounds!"));
		m_systemArrary[value] = sys;
	}

	SystemBase* getSystemByName(ESystemName name)
	{
		uint8 value = (uint8)name;
		const bool checkOK = m_systemArrary.size() > value;
		ensureMsgf(checkOK, TEXT("getSystem Error, index out of bounds"));
		auto p = m_systemArrary[value];
		if (p)
		{
			return p.Get();
		}
		return nullptr;
	}

};

Sys::Sys()
{
	m_imp = std::make_unique<Imp>();
}

Sys::~Sys()
{

}

SystemBase* Sys::getSystemByNameImp(ESystemName name)
{
	return m_imp->getSystemByName(name);
}

void Sys::addSystemImp(const TSharedPtr<SystemBase>& sys, const FString& name)
{
	return m_imp->addSystem(sys, name);
}
