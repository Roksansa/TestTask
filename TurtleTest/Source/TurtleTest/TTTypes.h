#pragma once

#include "CoreMinimal.h"
#include "TTTypes.generated.h"

UENUM(BlueprintType)
enum class ETTTurtleType: uint8
{
	NONE = 0,
	One,
	Two,
	Three,
	MAX
};
