#ifndef BOOST_ARCHIVE_DETAIL_BASIC_ISERIALIZER_HPP
#define BOOST_ARCHIVE_DETAIL_BASIC_ISERIALIZER_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// basic_iserializer.hpp: extenstion of type_info required for serialization.

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <cassert>
#include <cstdlib> // NULL
#include <boost/archive/detail/auto_link_archive.hpp>
#include <boost/archive/detail/basic_serializer.hpp>

#include <boost/archive/detail/abi_prefix.hpp> // must be the last header

namespace boost {

namespace serialization {
    class extended_type_info;
} // namespace serialization

// forward declarations
namespace archive {
namespace detail {

class BOOST_DECL_ARCHIVE basic_iarchive;
class BOOST_DECL_ARCHIVE basic_pointer_iserializer;

class BOOST_DECL_ARCHIVE basic_iserializer : public basic_serializer
{
private:
    basic_pointer_iserializer *bpis;
protected:
    explicit basic_iserializer(
        const boost::serialization::extended_type_info & type_
    );
    virtual ~basic_iserializer();
public:
    bool serialized_as_pointer() const {
        return bpis != NULL;
    }
    void set_bpis(basic_pointer_iserializer *bpis_){
        bpis = bpis_;
    }
    const basic_pointer_iserializer * get_bpis_ptr() const {
        return bpis;
    }
#if 0
    virtual void load_object_data(
        basic_iarchive & ar, 
        void *x,
        const unsigned int file_version
    ) const {
        assert(false);
    };
#endif
    virtual void load_object_data(
        basic_iarchive & ar, 
        void *x,
        const unsigned int file_version
    ) const = 0;
    // returns true if class_info should be saved
    virtual bool class_info() const = 0 ;
    // returns true if objects should be tracked
    virtual bool tracking() const = 0 ;
    // returns class version
    virtual unsigned int version() const = 0 ;
    // returns true if this class is polymorphic
    virtual bool is_polymorphic() const = 0;
    virtual void destroy(/*const*/ void *address) const = 0 ;
};

} // namespae detail
} // namespace archive
} // namespace boost

#include <boost/archive/detail/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // BOOST_ARCHIVE_DETAIL_BASIC_ISERIALIZER_HPP