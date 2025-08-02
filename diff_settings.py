#!/usr/bin/env python3

import os
import re


def add_custom_arguments(parser):
    parser.add_argument(
        "--overlay",
        default="psxus",
        dest="overlay",
    )


def apply(config, args):
    config["baseimg"] = "disks/us/SCUS_941.63"
    config["myimg"] = "build/us/main.bin"
    config["mapfile"] = "build/us/main.map"
    config["source_directories"] = ["src/psxus"]
    config["build_dir"] = "build/"
    config["expected_dir"] = "expected/"
    config["objdump_executable"] = "mipsel-linux-gnu-objdump"
    config["arch"] = "mipsel"
    config["makeflags"] = []
