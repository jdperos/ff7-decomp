#!/usr/bin/env python3


def add_custom_arguments(parser):
    parser.add_argument(
        "--overlay",
        default="main",
        dest="overlay",
    )


def apply(config, args):
    config["baseimg"] = "disks/us/SCUS_941.63"
    config["myimg"] = f"build/us/{args.overlay}.bin"
    config["mapfile"] = f"build/us/{args.overlay}.map"
    config["source_directories"] = [f"src/{args.overlay}"]
    config["build_dir"] = "build/"
    config["expected_dir"] = "expected/"
    config["objdump_executable"] = "mipsel-linux-gnu-objdump"
    config["arch"] = "mipsel"
    config["makeflags"] = []
