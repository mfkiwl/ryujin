//
// SPDX-License-Identifier: MIT
// Copyright (C) 2020 - 2022 by the ryujin authors
//

#pragma once

namespace ryujin
{
  namespace InitialStateLibrary
  {
    /**
     * Uniform initial state defined by a given primitive state.
     *
     * @ingroup InitialValues
     */
    template <int dim, typename Number, typename state_type>
    class Uniform : public InitialState<dim, Number, state_type, 2>
    {
    public:
      Uniform(const HyperbolicSystem &hyperbolic_system,
              const std::string subsection)
          : InitialState<dim, Number, state_type, 2>("uniform", subsection)
          , hyperbolic_system(hyperbolic_system)
      {
        primitive_[0] = hyperbolic_system.gamma();
        primitive_[1] = 3.0;
        primitive_[2] = 1.;
        this->add_parameter("primitive state",
                            primitive_,
                            "Initial 1d primitive state (rho, u, p)");
      }

      virtual state_type compute(const dealii::Point<dim> & /*point*/,
                                 Number /*t*/) final override
      {
        const auto temp = hyperbolic_system.from_primitive_state(primitive_);
        return hyperbolic_system.template expand_state<dim>(temp);
      }

    private:
      const HyperbolicSystem &hyperbolic_system;

      dealii::Tensor<1, 3, Number> primitive_;
    };
  } // namespace InitialStateLibrary
} // namespace ryujin