#pragma once

#include "GameFramework/Character.h"
#include "VRCharacter.generated.h"

UCLASS()
class VRFIRSTPERSON_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* CameraComp;

	/* Component to specify origin for the HMD */
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* VROriginComp;

	UPROPERTY(EditDefaultsOnly, Category = "VR")
	bool bPositionalHeadTracking;

	/* Motion Controllers */

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UMotionControllerComponent* LeftHandComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UMotionControllerComponent* RightHandComponent;

	void Move(float Value);
	void Strafe(float Value);

	void Grab();
	void Release();

public:
	// Sets default values for this character's properties
	AVRCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void SetupVROptions();

	/* Resets HMD Origin position and orientation */
	void ResetHMDOrigin();

	/* Toggle between Seated and Standing VR Tracking */
	void ToggleTrackingSpace();
	
};
