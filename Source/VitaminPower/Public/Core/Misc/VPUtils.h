#pragma once

class VPUtils
{
public:
	static void LogMessage(const FString& Message)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Message);
	}
	
	static void LogWarning(const FString& Message)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, Message);
	}
	
	static void LogError(const FString& Message)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, Message);
	}
	
};
