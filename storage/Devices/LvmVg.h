#ifndef STORAGE_LVM_VG_H
#define STORAGE_LVM_VG_H


#include "storage/Devices/Device.h"


namespace storage
{
    class LvmLv;

    //! A Volume Group of the Logical Volume Manager (LVM).
    class LvmVg : public Device
    {
    public:

	static LvmVg* create(Devicegraph* devicegraph, const std::string& name);
	static LvmVg* load(Devicegraph* devicegraph, const xmlNode* node);

	const std::string& get_name() const;
	void set_name(const std::string& name);

	virtual void check() const override;

	LvmLv* create_lvm_lv(const std::string& name);

    protected:

	class Impl;

	Impl& get_impl();
	const Impl& get_impl() const;

	virtual LvmVg* clone() const override;

    protected:

	LvmVg(Impl* impl);

    };


    bool is_lvm_vg(const Device* device);

    LvmVg* to_lvm_vg(Device* device);
    const LvmVg* to_lvm_vg(const Device* device);

}

#endif
