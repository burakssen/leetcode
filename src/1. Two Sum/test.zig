const std = @import("std");
const testing = std.testing;
const two_sum = @import("twosum.zig").two_sum;

test "Test 1" {
    std.debug.print("Two Sum Tests:\n", .{});
    var array = [_]i32{ 2, 7, 11, 15 }; // Make array mutable
    const target = 9;

    // Pass a mutable slice of the array to the function
    const result = two_sum(array[0..], target) catch |err| {
        std.debug.print("  Test 1| Error: {?}\n", .{err});
        try testing.expect(err == error.NoTwoSum); // Expect test to fail if there is an error
        return;
    };

    // At this point, we know `result` is a valid slice
    try testing.expect(result.len == 2);
    try testing.expect(result[0] == 0);
    try testing.expect(result[1] == 1);
    std.debug.print("  Test 1 Passed\n", .{});
}

test "Test 2" {
    var array = [_]i32{ 3, 2, 4 }; // Make array mutable
    const target = 6;

    // Pass a mutable slice of the array to the function
    const result = two_sum(array[0..], target) catch |err| {
        std.debug.print("  Test 2| Error: {?}\n", .{err});
        try testing.expect(err == error.NoTwoSum); // Expect test to fail if there is an error
        return;
    };

    // At this point, we know `result` is a valid slice
    try testing.expect(result.len == 2);
    try testing.expect(result[0] == 1);
    try testing.expect(result[1] == 2);
    std.debug.print("  Test 2 Passed\n", .{});
}

test "Test 3" {
    var array = [_]i32{ 3, 3 }; // Make array mutable
    const target = 6;

    // Pass a mutable slice of the array to the function
    const result = two_sum(array[0..], target) catch |err| {
        std.debug.print("  Test 3| Error: {?}\n", .{err});
        try testing.expect(err == error.NoTwoSum); // Expect test to fail if there is an error
        return;
    };

    // At this point, we know `result` is a valid slice
    try testing.expect(result.len == 2);
    try testing.expect(result[0] == 0);
    try testing.expect(result[1] == 1);
    std.debug.print("  Test 3 Passed\n", .{});
}
