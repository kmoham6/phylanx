// Copyright (c) 2018 Weile Wei
// Copyright (c) 2018 R. Tohid
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(PHYLANX_PREPEND_OPERATION_MAR_23_2019_0705AM)
#define PHYLANX_PREPEND_OPERATION_MAR_23_2019_0705AM

#include <phylanx/config.hpp>
#include <phylanx/execution_tree/primitives/base_primitive.hpp>
#include <phylanx/execution_tree/primitives/primitive_component_base.hpp>

#include <hpx/lcos/future.hpp>

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace phylanx { namespace execution_tree { namespace primitives
{
    class prepend_operation
      : public primitive_component_base
      , public std::enable_shared_from_this<prepend_operation>
    {
    protected:
        hpx::future<primitive_argument_type> eval(
            primitive_arguments_type const& operands,
            primitive_arguments_type const& args,
            eval_context ctx) const override;

    private:
        primitive_argument_type handle_list_operands(
            primitive_argument_type&& op1, primitive_argument_type&& rhs) const;

    public:
        static match_pattern_type const match_data;

        prepend_operation() = default;

        prepend_operation(primitive_arguments_type&& operands,
            std::string const& name, std::string const& codename);
    };

    inline primitive create_prepend_operation(hpx::id_type const& locality,
        primitive_arguments_type&& operands,
        std::string const& name = "", std::string const& codename = "")
    {
        return create_primitive_component(
            locality, "prepend", std::move(operands), name, codename);
    }
}}}

#endif
