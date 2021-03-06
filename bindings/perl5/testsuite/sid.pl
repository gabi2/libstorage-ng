#!/usr/bin/perl

use strict;
use Test::More tests => 7;
use Test::Exception;
use storage;


my $environment = new storage::Environment(1, $storage::ProbeMode_NONE, $storage::TargetMode_DIRECT);

my $storage = new storage::Storage($environment);

my $devicegraph = new storage::Devicegraph($storage);
my $sda = storage::Disk::create($devicegraph, "/dev/sda");
my $gpt = $sda->create_partition_table($storage::PtType_GPT);

is($sda->get_sid(), 42);
is($gpt->get_sid(), 43);

is($devicegraph->find_device(42)->get_sid(), 42);

throws_ok { $devicegraph->find_device(99) } 'storage::DeviceNotFound';

is($devicegraph->find_holder(42, 43)->get_source_sid(), 42);
is($devicegraph->find_holder(42, 43)->get_target_sid(), 43);

throws_ok { $devicegraph->find_holder(99, 99) } 'storage::HolderNotFound';
