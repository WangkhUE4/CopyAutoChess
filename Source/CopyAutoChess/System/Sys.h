#pragma once

#include <memory>


class SystemBase;
enum class ESystemName : uint8;

class Sys
{
public:
	Sys();;
	~Sys();

	void onCreateSys();

public:
	template<typename SysType>
	SysType* getSystemByName(ESystemName name)
	{
		static_assert(std::is_base_of<SystemBase, SysType>::value, "这个类不属于系统");
		auto p = getSystemByNameImp(name);
		if (p)
		{
			return static_cast<SysType*>(p);
		}
		return nullptr;
	}

private:
	SystemBase* getSystemByNameImp(ESystemName name);
	void addSystemImp(const TSharedPtr<SystemBase>& sys, const FString& name);

	//--------------------------------------------------------------------------
	template<typename SysType>
	void createSystem()
	{
		constexpr bool isBase = std::is_base_of<SystemBase, SysType>::value;
		static_assert(isBase, "这个类不属于系统");
		if (!isBase)
		{
			return;
		}

		auto p = MakeShared<SysType>();
		addSystemImp(p, p->getSystemName());
	}

private:
	struct Imp;
	std::unique_ptr<Imp> m_imp;
};
