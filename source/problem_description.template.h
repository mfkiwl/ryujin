//
// SPDX-License-Identifier: MIT
// Copyright (C) 2020 by the ryujin authors
//

#ifndef PROBLEM_DESCRIPTION_TEMPLATE_H
#define PROBLEM_DESCRIPTION_TEMPLATE_H

#include "problem_description.h"

namespace ryujin
{
  using namespace dealii;


  template <int dim, typename Number>
  ProblemDescription<dim, Number>::ProblemDescription(
      const std::string &subsection /*= "ProblemDescription"*/)
      : ParameterAcceptor(subsection)
  {
    description_ = "Euler";
    add_parameter(
        "Description",
        description_,
        "Description - valid options are \"Euler\" and \"Navier Stokes\"");

    mu_ = Number(1.e-3);
    add_parameter("mu", mu_, "Navier Stokes: Shear viscosity");

    lambda_ = Number(0.);
    add_parameter("lambda", lambda_, "Navier Stokes: Bulk viscosity");

    kappa_ = Number(5.e-3);
    add_parameter("kappa", kappa_, "Navier Stokes: Thermal conductivity");
  }


#ifndef DOXYGEN
  template <>
  const std::array<std::string, 3> ProblemDescription<1>::component_names{
      "rho", "m", "E"};

  template <>
  const std::array<std::string, 4> ProblemDescription<2>::component_names{
      "rho", "m_1", "m_2", "E"};

  template <>
  const std::array<std::string, 5> ProblemDescription<3>::component_names{
      "rho", "m_1", "m_2", "m_3", "E"};

  template <>
  const std::array<std::string, 3>
      ProblemDescription<1, float>::component_names{"rho", "m", "E"};

  template <>
  const std::array<std::string, 4>
      ProblemDescription<2, float>::component_names{"rho", "m_1", "m_2", "E"};

  template <>
  const std::array<std::string, 5>
      ProblemDescription<3, float>::component_names{
          "rho", "m_1", "m_2", "m_3", "E"};
#endif

} /* namespace ryujin */

#endif /* PROBLEM_DESCRIPTION_TEMPLATE_H */
