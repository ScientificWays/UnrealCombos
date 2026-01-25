// Scientific Ways

#pragma once

#include "UnrealCombos.h"

#include "ScWTypes_CommonDelegates.h"
#include "Gameplay/Characters/ScWCharacterData_InitInterface.h"

#include "ScWComboStateComponent.generated.h"

UENUM(BlueprintType)
enum class EComboState : uint8
{
	Reset,
	ReadyForMove,
	NotYetReadyForMove,
	Failed,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FComboStateChangedSignature, EComboState, InNewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FComboMoveEventSignature, const class UScWComboMoveData*, InComboMoveData);

/**
 * 
 */
UCLASS(Blueprintable, meta = (DisplayName = "[ScW] Combo State Component", BlueprintSpawnableComponent))
class UNREALCOMBOS_API UScWComboStateComponent : public UActorComponent, public IScWCharacterData_InitInterface
{
	GENERATED_BODY()
	
public:

	UScWComboStateComponent();
	
//~ Begin Statics
public:

	UFUNCTION(Category = "Statics", BlueprintCallable, BlueprintPure)
	static UScWComboStateComponent* GetComboStateComponentFromActor(const AActor* InActor);

	UFUNCTION(Category = "Statics", BlueprintCallable, BlueprintPure)
	static UScWComboStateComponent* GetComboStateComponentFromActorInfo(const FGameplayAbilityActorInfo& InActorInfo);
//~ End Statics
	
//~ Begin Initialize
protected:
	virtual void OnRegister() override; // UActorComponent
	virtual void InitFromCharacterData(const class UScWCharacterData* InInitCharacterData) override; // IScWCharacterData_InitInterface
	virtual void BeginPlay() override; // UActorComponent
//~ End Initialize

//~ Begin Combo
public:

	UFUNCTION(Category = "Combo", BlueprintCallable)
	bool IsValid() const { return !AvailableCombos.IsEmpty(); }

	UFUNCTION(Category = "Combo", BlueprintCallable)
	EComboState GetCurrentComboState() const { return CurrentComboState; }

	UFUNCTION(Category = "Combo", BlueprintCallable)
	const class UScWComboData* GetRelevantCombo() const { return RelevantCombo; }

	UFUNCTION(Category = "Combo | Queue", BlueprintCallable)
	const class UScWComboMoveData* GetQueuedComboMove() const { return QueuedComboMove; }

	UFUNCTION(Category = "Combo | Queue", BlueprintCallable)
	bool QueueComboMove(const class UScWComboMoveData* InComboMoveData);

	UFUNCTION(Category = "Combo | Queue", BlueprintCallable)
	void AcceptQueuedComboMove();

	UFUNCTION(Category = "Combo | Queue", BlueprintCallable)
	void DenyQueuedComboMove();

	UPROPERTY(Category = "Combo | Queue", BlueprintAssignable)
	FComboMoveEventSignature OnComboMoveQueuedDelegate;

	UPROPERTY(Category = "Combo | Queue", BlueprintAssignable)
	FComboMoveEventSignature OnQueuedComboMoveAcceptedDelegate;

	UPROPERTY(Category = "Combo | Queue", BlueprintAssignable)
	FComboMoveEventSignature OnQueuedComboMoveDeniedDelegate;

	UFUNCTION(Category = "Combo", BlueprintCallable, meta = (AdvancedDisplay = "InUpdateRelevantCombo, InResetIfNoRelevantCombo"))
	void AddComboMove(const class UScWComboMoveData* InComboMoveData, bool InUpdateRelevantCombo = true, bool InResetIfNoRelevantCombo = true);

	UFUNCTION(Category = "Combo", BlueprintCallable, meta = (AdvancedDisplay = "InUpdateRelevantComboOnResetOrFail"))
	void SetComboState(EComboState InState, bool InUpdateRelevantComboOnResetOrFail = true);

	UFUNCTION(Category = "Combo", BlueprintCallable, meta = (AdvancedDisplay = "InResetIfNoRelevantCombo", KeyWords = "GetComboFromCurrentMoves"))
	bool UpdateRelevantComboFromCurrentMoves(bool InResetIfNoRelevantCombo = true);

	UPROPERTY(Category = "Combo", BlueprintAssignable)
	FComboMoveEventSignature OnComboMoveAddedDelegate;

	UPROPERTY(Category = "Combo", BlueprintAssignable)
	FComboStateChangedSignature OnComboStateChangedDelegate;

protected:

	UPROPERTY(Category = "Combo", BlueprintReadOnly)
	EComboState CurrentComboState;

	UPROPERTY(Category = "Combo", BlueprintReadOnly)
	TObjectPtr<const class UScWComboMoveData> QueuedComboMove;

	UPROPERTY(Category = "Combo", EditDefaultsOnly, BlueprintReadOnly)
	TArray<TObjectPtr<const class UScWComboMoveData>> CurrentComboMoves;

	UPROPERTY(Category = "Combo", EditDefaultsOnly, BlueprintReadOnly)
	TArray<TObjectPtr<const class UScWComboData>> AvailableCombos;

	UPROPERTY(Category = "Combo", EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<const class UScWComboData> RelevantCombo;

	UPROPERTY(Category = "Combo", BlueprintAssignable)
	FSuccessSignature OnRelevantComboUpdated;
//~ End Combo

//~ Begin Effects
public:

	UFUNCTION(Category = "Effects", BlueprintCallable)
	FActiveGameplayEffectHandle ApplyComboFailedOwnerEffect();

	UPROPERTY(Category = "Effects", EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayEffect> ComboFailedOwnerEffectClass;
//~ End Effects
};
