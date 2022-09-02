//
// SPDX-License-Identifier: MIT
// Copyright (C) 2020 - 2022 by the ryujin authors
//

#pragma once

#include "hyperbolic_system.h"

namespace ryujin
{
  HyperbolicSystem::HyperbolicSystem(
      const std::string &subsection /*= "HyperbolicSystem"*/)
      : ParameterAcceptor(subsection)
  {
    gravity_ = 9.81;
    add_parameter("gravity", gravity_, "Gravitational constant [m/s^2]");

    mannings_ = 0.;
    add_parameter(
        "mannings", mannings_, "Roughness coefficient for friction source");

    reference_water_depth_ = 1.;
    add_parameter("reference water depth",
                  reference_water_depth_,
                  "Problem specific water depth reference");

    dry_state_relaxation_ = 100.;
    add_parameter("dry state relaxation",
                  dry_state_relaxation_,
                  "Problem specific dry-state relaxation parameter");
  }


#ifndef DOXYGEN
  template <>
  const std::array<std::string, 2> HyperbolicSystem::component_names<1>{
      {"h", "m"}};

  template <>
  const std::array<std::string, 3> HyperbolicSystem::component_names<2>{
      {"h", "m_1", "m_2"}};

  template <>
  const std::array<std::string, 2>
      HyperbolicSystem::primitive_component_names<1>{{"h", "v"}};

  template <>
  const std::array<std::string, 3>
      HyperbolicSystem::primitive_component_names<2>{{"h", "v_1", "v_2"}};

  template <>
  const std::array<std::string, 1> HyperbolicSystem::precomputed_names<1>{
      {"bathymetry"}};

  template <>
  const std::array<std::string, 1> HyperbolicSystem::precomputed_names<2>{
      {"bathymetry"}};
#endif

} /* namespace ryujin */