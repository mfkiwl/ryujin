//
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// Copyright (C) 2022 - 2023 by the ryujin authors
//

#pragma once

#include <compile_time_options.h>
#include <convenience_macros.h>

#include <deal.II/base/parameter_acceptor.h>

namespace ryujin
{
  namespace Euler
  {
    /**
     * The parabolic subsystem of the compressible Euler equations. This is
     * just the idenity operator.
     *
     * @ingroup EulerEquations
     */
    class ParabolicSystem final : public dealii::ParameterAcceptor
    {
    public:
      /**
       * The name of the hyperbolic system as a string.
       */
      static inline const std::string problem_name = "Identity";

      /**
       * This parabolic subsystem represents an identity.
       */
      static constexpr bool is_identity = true;

      /**
       * Constructor.
       */
      ParabolicSystem(const std::string &subsection = "/ParabolicSystem");

      unsigned int n_parabolic_state_vectors() const
      {
        return parabolic_component_names_.size();
      }

      ACCESSOR_READ_ONLY(parabolic_component_names);

    private:
      const std::vector<std::string> parabolic_component_names_;
    }; /* ParabolicSystem */


    /*
     * -------------------------------------------------------------------------
     * Inline definitions
     * -------------------------------------------------------------------------
     */


    inline ParabolicSystem::ParabolicSystem(const std::string &subsection)
        : ParameterAcceptor(subsection)
    {
    }

  } // namespace Euler
} // namespace ryujin
