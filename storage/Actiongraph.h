#ifndef STORAGE_ACTIONGRAPH_H
#define STORAGE_ACTIONGRAPH_H


#include <memory>
#include <string>
#include <vector>
#include <boost/noncopyable.hpp>

#include "storage/Graphviz.h"


namespace storage
{

    class Storage;
    class Devicegraph;


    namespace Action
    {
	class Base;
    }


    enum Side {
	LHS, RHS
    };


    class Actiongraph : private boost::noncopyable
    {
    public:

	Actiongraph(const Storage& storage, const Devicegraph* lhs, const Devicegraph* rhs);

	const Storage& get_storage() const;

	const Devicegraph* get_devicegraph(Side side) const;

	void print_graph() const;
	void write_graphviz(const std::string& filename, GraphvizFlags flags =
			    GraphvizFlags::NONE) const;

	bool empty() const;

	size_t num_actions() const;

	/**
	 * Sorted according to dependencies among actions.
	 */
	std::vector<const Action::Base*> get_commit_actions() const;

	// TODO add Action to the public interface and use get_commit_actions instead
	std::vector<std::string> get_commit_actions_as_strings() const;

    public:

        class Impl;

        Impl& get_impl() { return *impl; }
        const Impl& get_impl() const { return *impl; }

    private:

        std::shared_ptr<Impl> impl;

    };

}


#endif
