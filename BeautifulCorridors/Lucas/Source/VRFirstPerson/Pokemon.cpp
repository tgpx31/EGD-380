// Fill out your copyright notice in the Description page of Project Settings.

#include "VRFirstPerson.h"
#include "Pokemon.h"

APokemon::APokemon()
{
}

// Sets default values
APokemon::APokemon(const FObjectInitializer& ObjectInitializer)
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = ObjectInitializer.CreateAbstractDefaultSubobject<UStaticMeshComponent>(this, TEXT("MyMesh"));

	pokemonAsset = Cast<UStaticMesh>(ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh")));
	RootComponent = StaticMeshComponent;

	//RootComponent = PokemonMeshComponent;

}

void APokemon::initMesh(FString filepath)
{
	pokemonAsset = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, *filepath)); //static ConstructorHelpers::FObjectFinder<UStaticMesh>(pokemonAsset) ((*filepath));//
	StaticMeshComponent->SetStaticMesh(pokemonAsset);
}

// Called when the game starts or when spawned
void APokemon::BeginPlay()
{
	//RootComponent = StaticMeshComponent;
	//pokemonAsset->AddToRoot();
	//StaticMeshComponent->SetMobility(EComponentMobility::Movable);
	Super::BeginPlay();
}

// Called every frame
void APokemon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

//// Called to bind functionality to input
//void APokemon::SetupPlayerInputComponent(class UInputComponent* InputComponent)
//{
//	Super::SetupPlayerInputComponent(InputComponent);
//}

void APokemon::useMove(int index, APokemon* target)
{
	if (mpMoveList[index]->mPP <= 0)
	{
		//tell the user the move is out of pp, return to battle loop
		GLog->Log("The move failed! It is out of PP!");
		return;
	}

	if (mpMoveList[index]->mAccuracy >= randomNumber(MIN_ACCURACY, MAX_RAND_NUM))
	{
		//display what move the user used
		GLog->Log(mName.ToString() + " used " + mpMoveList[index]->mName.ToString() + ".");
		doDamage(mpMoveList[index], target);

		//reduce PP
		--mpMoveList[index]->mPP;
		if (mpMoveList[index]->mPP <= 0)
			mpMoveList[index]->mPP = 0;
	}
	else
	{
		//tell user the attack missed
		GLog->Log("The attack missed!");
	}
}

void APokemon::doDamage(AAttack* move, APokemon* Other)
{
	int damage;
	float weakness = 1;
	float STAB_MULT = 1;

	// Check if Heal || Stat boost || Damage
	if (move->mMoveAction == MoveAction::heal)
	{
		// These moves heal you
		modifyHealth(-static_cast<int>(mMaxHealth / 2));
		if (mCurrentHealth > mMaxHealth)
		{
			// Cap at the maxHealth
			modifyHealth(mCurrentHealth - mMaxHealth);
		}

		//inform user of healing
		GLog->Log(mName.ToString() + " healed!");
		return;
	}
	else if (move->mMoveAction == MoveAction::stat_change)
	{
		// Raise the corresponding stat
		modifyStatCoefficient(move->mAffectedStatIndex, move->mStatMultiplier);

		if (mStatCoefficients[move->mAffectedStatIndex] >= 4.0f)
		{
			mStatCoefficients[move->mAffectedStatIndex] = 4.0f;
		}
		else if (mStatCoefficients[move->mAffectedStatIndex] <= .25f)
		{
			mStatCoefficients[move->mAffectedStatIndex] = .25f;
		}

		if (move->mStatMultiplier > 1)
		{
			//tell the user about the buff
			GLog->Log("The corresponding stat was increased!");
		}
			
		return;
	}

	// Random number between 85 and 100
	int randNumber = randomNumber(MIN_RAND_NUM, MAX_RAND_NUM);

	// Check the move used
	// Is it the same type as the Pokemon using it?
	if (move->mType == mType[0] || move->mType == mType[1])
		STAB_MULT = 1.5f;
	else
		STAB_MULT = 1;

	// Is the Other Pokemon weak or resistant?
	weakness = calcResistance(move->mType, Other);
	if (weakness > 1)
	{
		//tell the user it was Super Effective!
		GLog->Log("The move was Super Effective!");
	}	
	else if (weakness < 1 && weakness > 0)
	{
		//tell the user it wasn't very effective :(
		GLog->Log("The move wasn't very effective...");
	}	
	else if (weakness == 0)
	{
		//tell the user it did NOTHING.
		GLog->Log("The move didn't do any damage!");
		return;
	}


	// is the move Special?
	if (move->isSpecial)
		damage = static_cast<int>(((((2 * LEVEL / 5 + 2) * mSpAttack * move->mPower / mSpDefense) / 50) + 2) * STAB_MULT * weakness * randNumber / 100);
	else
		damage = static_cast<int>(((((2 * LEVEL / 5 + 2) * mAttack * move->mPower / mDefense) / 50) + 2) * STAB_MULT * weakness * randNumber / 100);

	// Deal the damage to the target
	//Tell the user how much damage was done
	Other->modifyHealth(damage);
	GLog->Log(mName.ToString() + " did " + FString::FromInt(damage) + " damage to " + Other->mName.ToString());

	if (Other->mCurrentHealth < 0)
	{
		//tell the user if the enemy fainted!
		GLog->Log(Other->mName.ToString() + " fainted!");
	}
	else
	{
		//tell the user how much health the enemy has left
		GLog->Log(Other->mName.ToString() + " has " + FString::FromInt(Other->mCurrentHealth) + " health left!");
	}	
}

float APokemon::calcResistance(Type moveType, APokemon* other)
{
	float finalMult = 1;

	int value = (int)moveType;

	// Compare the moveType to the Pokemons two types
	finalMult *= TypeChart[(int)moveType][(int)other->mType[0]];
	if (other->mType[1] == Type::NONE)
		finalMult *= 1;
	else
		finalMult *= TypeChart[(int)moveType][(int)other->mType[1]];

	return finalMult;
}

void APokemon::displayMoveList()
{
	for (int i = 0; i < MOVE_AMOUNT; ++i)
	{
		GLog->Log(mpMoveList[i]->mName.ToString() + FString("[") + FString::FromInt(i + 1) + FString("]"));		
	}
}

int randomNumber(int min, int max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}

Type APokemon::getTypeFromData(int32 type)
{
	switch (type)
	{
	case 0: return Type::normal;
		break;
	case 1: return Type::fighting;
		break;
	case 2: return Type::flying;
		break;
	case 3: return Type::poison;
		break;
	case 4: return Type::ground;
		break;
	case 5: return Type::rock;
		break;
	case 6: return Type::bug;
		break;
	case 7: return Type::ghost;
		break;
	case 8: return Type::fire;
		break;
	case 9: return Type::water;
		break;
	case 10: return Type::grass;
		break;
	case 11: return Type::electric;
		break;
	case 12: return Type::psychic;
		break;
	case 13: return Type::ice;
		break;
	case 14: return Type::dragon;
		break;
	case 15: return Type::dark;
		break;
	case 16: return Type::NONE;
		break;
	default: return Type::NONE;
		break;
	}
}

void APokemon::setTypes(int32 type1, int32 type2)
{
	mType.Add(getTypeFromData(type1));
	mType.Add(getTypeFromData(type2));
}