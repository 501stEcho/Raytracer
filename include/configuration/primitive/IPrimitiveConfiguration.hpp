/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "object/IPrimitive.hpp"
#include "object/PrimitiveFactory.hpp"

namespace Raytracer {

    class IPrimitiveConfiguration {
    public:
        [[nodiscard]] virtual Primitive toPrimitive() const = 0;

        virtual ~IPrimitiveConfiguration() = default;
    };

}
