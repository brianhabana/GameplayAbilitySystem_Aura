// Copyright Brian Habana


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

<<<<<<< HEAD
UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams WCParams)
{
	if (OverlayWidgetClass == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);

=======
UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
>>>>>>> temp-branch
		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
<<<<<<< HEAD
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass uninitalized, please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass uninitalized, please fill out BP_AuraHUD"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
=======
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class unitialized, pleasse fill out BP_AuraHUD"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);

>>>>>>> temp-branch
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
<<<<<<< HEAD
	
=======
>>>>>>> temp-branch
	Widget->AddToViewport();
}

