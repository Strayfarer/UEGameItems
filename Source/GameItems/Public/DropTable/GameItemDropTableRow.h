// Copyright Bohdon Sayre, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameItemDropContent.h"
#if ENGINE_MAJOR_VERSION < 5 || (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION < 8)
#include "InstancedStruct.h"
#endif
#include "Engine/DataTable.h"
#include "GameItemDropTableRow.generated.h"


/**
 * Row struct for a game item drop table.
 */
USTRUCT(BlueprintType)
struct GAMEITEMS_API FGameItemDropTableRow : public FTableRowBase
{
	GENERATED_BODY()

	/** The items and quantities to create if the entry is selected. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExcludeBaseStruct, ShowTreeView))
	TInstancedStruct<FGameItemDropContent> Content = TInstancedStruct<FGameItemDropContent>::Make<FGameItemDropContent_Item>();

	virtual void OnDataTableChanged(const UDataTable* InDataTable, const FName InRowName) override;
};
