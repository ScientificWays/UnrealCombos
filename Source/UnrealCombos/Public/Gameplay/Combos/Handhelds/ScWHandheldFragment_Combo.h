// Scientific Ways

#pragma once

#include "UnrealCombos.h"

#include "Gameplay/Handhelds/ScWHandheldFragment.h"

#include "ScWHandheldFragment_Combo.generated.h"

/**
 *
 */
UCLASS(meta = (DisplayName = "[ScW] Handheld Fragment (Combo)"))
class UNREALCOMBOS_API UScWHandheldFragment_Combo : public UScWHandheldFragment
{
	GENERATED_BODY()

public:	

	UScWHandheldFragment_Combo();
	
//~ Begin Swing
public:
	virtual float BP_ModifySwingBaseDamage_Implementation(const class AScWHandheld* InHandheld, float InDamage) const override; // UScWHandheldFragment
	virtual TSubclassOf<class UScWDamageType> BP_ModifySwingBaseDamageTypeClass_Implementation(const class AScWHandheld* InHandheld, TSubclassOf<class UScWDamageType> InDamageTypeClass) const override; // UScWHandheldFragment

	UPROPERTY(Category = "Swing", EditDefaultsOnly, BlueprintReadOnly)
	float PostSwingComboTimeWindow;
//~ End Swing

//~ Begin Swing Variants
public:
	virtual void BP_ModifySwingVariants_Implementation(const class AScWHandheld* InHandheld, TArray<FScWMeleeSwingVariantData>& InOutVariants) const override; // UScWHandheldFragment
//~ End Swing Variants
};
