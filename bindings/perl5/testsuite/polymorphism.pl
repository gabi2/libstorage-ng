#!/usr/bin/perl

use strict;
use Test::More tests => 12;
use Test::Exception;
use storage;

my $environment = new storage::Environment(1, $storage::ProbeMode_NONE, $storage::TargetMode_DIRECT);

my $storage = new storage::Storage($environment);

my $devicegraph = new storage::Devicegraph($storage);
my $sda = storage::Disk::create($devicegraph, "/dev/sda");
my $gpt = $sda->create_partition_table($storage::PtType_GPT);

is($sda->get_sid(), 42);
is($gpt->get_sid(), 43);

my $tmp1 = $devicegraph->find_device(42);
is(storage::is_disk($tmp1), 1);
isnt(storage::to_disk($tmp1), undef);
isnt(storage::is_partition_table($tmp1), 1);
throws_ok { storage::to_partition_table($tmp1) } 'storage::DeviceHasWrongType';
throws_ok { storage::to_partition_table($tmp1) } 'storage::Exception';

my $tmp2 = $devicegraph->find_device(43);
is(storage::is_partition_table($tmp2), 1);
isnt(storage::to_partition_table($tmp2), undef);
isnt(storage::is_disk($tmp2), 1);
throws_ok { storage::to_disk($tmp2) } 'storage::DeviceHasWrongType';
throws_ok { storage::to_disk($tmp2) } 'storage::Exception';
