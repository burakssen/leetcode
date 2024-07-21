const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});

    const optimize = b.standardOptimizeOption(.{});

    const twosum_lib = b.addStaticLibrary(.{
        .name = "twosum",
        .root_source_file = b.path("src/1. Two Sum/twosum.zig"),
        .target = target,
        .optimize = optimize,
    });

    b.installArtifact(twosum_lib);

    const test_step = b.step("test", "Run unit tests");

    const run_twosum_unit_test = b.addSystemCommand(&[_][]const u8{
        "zig",
        "test",
        "src/1. Two Sum/test.zig",
    });

    test_step.dependOn(&run_twosum_unit_test.step);
}
