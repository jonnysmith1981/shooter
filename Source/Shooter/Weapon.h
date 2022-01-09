// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "AmmoType.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	EWT_SubmachineGun UMETA(DisplayName = "Submachine Gun"),
	EWT_AssaultRifle UMETA(DisplayName = "Assault Rifle"),

	EWT_MAX UMETA(DisplayName = "Default MAX")
};

/**
 * 
 */
UCLASS()
class SHOOTER_API AWeapon : public AItem
{
	GENERATED_BODY()
	
public:
	AWeapon();
	virtual void Tick(float DeltaTime) override;

protected:
	void StopFalling();

private:
	FTimerHandle ThrowWeaponTimer;
	float ThrowWeaponTime;
	bool bFalling;

	/** Ammo count for this weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Weapon Props", meta = (AllowPrivateAccess = "true"))
	int32 AmmoCount;

	/** Maximum ammo this weapon can hold */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Weapon Props", meta = (AllowPrivateAccess = "true"))
	int32 MagazineCapacity;

	/** Type of weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Weapon Props", meta = (AllowPrivateAccess = "true"))
	EWeaponType WeaponType;

	/** The type of ammo for this weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Weapon Props", meta = (AllowPrivateAccess = "true"))
	EAmmoType AmmoType;

	/** Name of the reload montage section for this weapon*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Weapon Props", meta = (AllowPrivateAccess = "true"))
	FName ReloadMontageSection;

	/** True when the clip is moving during the reload */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "Weapon Props", meta = (AllowPrivateAccess = "true"))
	bool bMovingClip;

	/** The name of the skeletal bone representing the ammo clip */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Weapon Props", meta = (AllowPrivateAccess = "true"))
	FName ClipBoneName;
public:
	// Adds an impulse to the drop-weapon mechanism
	void ThrowWeapon();

	FORCEINLINE int32 GetAmmoCount() const{ return AmmoCount; };
	FORCEINLINE int32 GetMagazineCapacity() const { return MagazineCapacity; };

	/** Called from character class when firing weapon */
	void DecrementAmmo();

	FORCEINLINE EWeaponType GetWeaponType() const { return WeaponType; };
	FORCEINLINE EAmmoType GetAmmoType() const { return AmmoType; };
	FORCEINLINE FName GetReloadMontageSection() const{ return ReloadMontageSection; };

	void ReloadAmmo(int32 Amount);
	FORCEINLINE FName GetClipBoneName() const { return ClipBoneName; };

	FORCEINLINE void SetMovingClip(bool Moving) { bMovingClip = Moving; };
};
