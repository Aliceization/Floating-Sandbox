/***************************************************************************************
 * Original Author:		Gabriele Giuseppini
 * Created:				2018-01-21
 * Copyright:			Gabriele Giuseppini  (https://github.com/GabrieleGiuseppini)
 ***************************************************************************************/
#pragma once

#include "GameException.h"
#include "Vectors.h"

#include <picojson/picojson.h>

#include <string>

struct StructuralMaterial
{
    std::string Name;
    float Strength;
    float Mass;
    float Stiffness;
    vec4f RenderColor;
    bool IsHull;

    enum class MaterialSoundType
    {
        Cable,
        Glass,
        Metal,
        Wood,
    };

    MaterialSoundType MaterialSound;

    static StructuralMaterial Create(picojson::object const & structuralMaterialJson);

    static MaterialSoundType StrToMaterialSoundType(std::string const & str);

private:

    StructuralMaterial(
        std::string name,
        float strength,
        float mass,
        float stiffness,
        vec4f renderColor,
        bool isHull,
        MaterialSoundType materialSound)
        : Name(name)
        , Strength(strength)
        , Mass(mass)
        , Stiffness(stiffness)
        , RenderColor(renderColor)
        , IsHull(isHull)
        , MaterialSound(materialSound)
    {}
};

struct ElectricalMaterial
{
    std::string Name;

    enum class ElectricalElementType
    {
        Lamp,
        Cable,
        Generator
    };

    ElectricalElementType ElectricalType;

    bool IsSelfPowered;

    static ElectricalMaterial Create(picojson::object const & electricalMaterialJson);

    static ElectricalElementType StrToElectricalElementType(std::string const & str);

private:

    ElectricalMaterial(
        std::string name,
        ElectricalElementType electricalType,
        bool isSelfPowered)
        : Name(name)
        , ElectricalType(electricalType)
        , IsSelfPowered(isSelfPowered)
    {
    }
};
