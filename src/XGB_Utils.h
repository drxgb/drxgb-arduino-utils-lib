#pragma once

// Funções utilitárias
#include "functions.h"

// Coleções
#include "Collections/List.h"

// Componentes
#include "Components/AnalogComponent.h"
#include "Components/Button.h"
#include "Components/DigitalComponent.h"
#include "Components/SevenSegmentDisplay.h"

// Contratos
#include "Contracts/Listenable.h"

// Decodificadores
#include "IO/Decoders/DecimalDisplayDecoder.h"

// Definições de tipo
namespace XGB
{
	using Led = DigitalComponent;
}