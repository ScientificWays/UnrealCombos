// Scientific Ways

#pragma once

#include "UnrealCommons.h"

class FUnrealCombosModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
