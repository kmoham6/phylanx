//  Copyright (c) 2017 Alireza Kheirkhahan
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(PHYLANX_PRIMITIVES_FILE_WRITE_CSV_OCT_26_2017_0129PM)
#define PHYLANX_PRIMITIVES_FILE_WRITE_CSV_OCT_26_2017_0129PM

#include <phylanx/config.hpp>
#include <phylanx/execution_tree/primitives/base_primitive.hpp>
#include <phylanx/execution_tree/primitives/primitive_component_base.hpp>

#include <hpx/futures/future.hpp>

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace phylanx { namespace execution_tree { namespace primitives
{
    class file_write_csv
      : public primitive_component_base
      , public std::enable_shared_from_this<file_write_csv>
    {
    protected:
        hpx::future<primitive_argument_type> eval(
            primitive_arguments_type const& operands,
            primitive_arguments_type const& args, eval_context ctx) const;
    public:
        static match_pattern_type const match_data;

        file_write_csv() = default;

        file_write_csv(primitive_arguments_type&& operands,
            std::string const& name, std::string const& codename);

    private:
        hpx::future<primitive_argument_type> write_to_file_csv(
            ir::node_data<double>&& val, std::string&& filename) const;
    };

    inline primitive create_file_write_csv(hpx::id_type const& locality,
        primitive_arguments_type&& operands,
        std::string const& name = "", std::string const& codename = "")
    {
        return create_primitive_component(
            locality, "file_write_csv", std::move(operands), name, codename);
    }
}}}

#endif
