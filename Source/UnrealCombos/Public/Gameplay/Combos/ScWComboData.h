// Scientific Ways

#pragma once

#include "UnrealCombos.h"

#include "Gameplay/Handhelds/ScWTypes_Handhelds.h"

#include "ScWComboData.generated.h"

/**
 *
 */
UCLASS(const, Blueprintable, BlueprintType, meta = (DisplayName = "[ScW] Combo Data"))
class UNREALCOMBOS_API UScWComboData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:	

	UScWComboData();

//~ Begin UI
public:

	UPROPERTY(Category = "UI", EditDefaultsOnly, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(Category = "UI", EditDefaultsOnly, BlueprintReadOnly, meta = (AssetBundles = "Game"))
	TSoftObjectPtr<UTexture2D> Image;
//~ End UI

//~ Begin Moves
public:

	UPROPERTY(Category = "Moves", EditDefaultsOnly, BlueprintReadOnly)
	TArray<TObjectPtr<const class UScWComboMoveData>> Moves;

	UPROPERTY(Category = "Moves", EditDefaultsOnly, BlueprintReadOnly)
	bool bUseLastMoveModifiers;
//~ End Moves
	
//~ Begin Power
public:

	UPROPERTY(Category = "Power", EditDefaultsOnly, BlueprintReadOnly)
	float ComboPowerMul;

	UFUNCTION(Category = "Power", BlueprintNativeEvent, BlueprintCallable, meta = (DisplayName = "Get Handheld PowerMul"))
	float BP_GetHandheldPowerMul(const class AScWHandheld* InHandheld) const;
//~ End Power

//~ Begin Damage
public:

	UFUNCTION(Category = "Damage", BlueprintNativeEvent, BlueprintCallable, meta = (DisplayName = "Modify HandheldDamage"))
	float BP_ModifyHandheldDamage(const class AScWHandheld* InHandheld, float InDamage) const;

	UFUNCTION(Category = "Damage", BlueprintNativeEvent, BlueprintCallable, meta = (DisplayName = "Modify HandheldDamageTypeClass"))
	TSubclassOf<class UScWDamageType> BP_ModifyHandheldDamageTypeClass(const class AScWHandheld* InHandheld, TSubclassOf<class UScWDamageType> InDamageTypeClass) const;

	UPROPERTY(Category = "Damage", EditDefaultsOnly, BlueprintReadOnly)
	float DamageMul;

	UPROPERTY(Category = "Damage", EditDefaultsOnly, BlueprintReadOnly)
	float DamageAdditive;

	UPROPERTY(Category = "Damage", EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class UScWDamageType> OverrideDamageTypeClass;

	UPROPERTY(Category = "Damage", EditDefaultsOnly, BlueprintReadOnly)
	float DamageImpactImpulseMul;
//~ End Damage

//~ Begin Swing Variants
public:

	UFUNCTION(Category = "Swing Variants", BlueprintNativeEvent, BlueprintCallable, meta = (DisplayName = "Modify SwingVariants"))
	void BP_ModifySwingVariants(const class AScWHandheld* InHandheld, const TArray<FScWMeleeSwingVariantData>& InVariants, TArray<FScWMeleeSwingVariantData>& OutVariants) const;

	UPROPERTY(Category = "Swing Variants", EditDefaultsOnly, BlueprintReadOnly)
	TArray<FScWMeleeSwingVariantData> OverrideSwingVariants;
//~ End Swing Variants
};
