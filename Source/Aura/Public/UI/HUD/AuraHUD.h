// Copyright Brian Habana

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UOverlayWidgetController;
class UAuraUserWidget;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAuraUserWidget> OverlayWidget;

<<<<<<< HEAD
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams WCParams);
=======
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
>>>>>>> temp-branch

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
protected:

<<<<<<< HEAD
=======
	
>>>>>>> temp-branch
private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

<<<<<<< HEAD
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
=======
	UPROPERTY();
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere);
>>>>>>> temp-branch
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
