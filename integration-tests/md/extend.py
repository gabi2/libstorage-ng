#!/usr/bin/python

# requirements: md raid /dev/md0 with partitions sdb[1-4] and unused partition sdb5


from sys import exit
from storage import *
from storageitu import *


set_logger(get_logfile_logger())

environment = Environment(False)

storage = Storage(environment)

staging = storage.get_staging()

sdb5 = Partition.find(staging, "/dev/sdb5")

md = Md.find(staging, "/dev/md0")
md.set_md_level(RAID0)

md_user = md.add_device(sdb5)
md_user.spare = True

print staging

commit(storage)

