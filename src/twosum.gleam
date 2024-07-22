import gleam/list

pub fn two_sum(nums: List(Int), target: Int) -> List(Int) {
  find_pair(nums, target, 0)
}

fn find_pair(nums: List(Int), target: Int, index: Int) -> List(Int) {
  case nums {
    [] -> []
    [first, ..rest] -> {
      case find_complement(rest, target - first, index + 1) {
        Ok(complement_index) -> [index, complement_index]
        Error(Nil) -> find_pair(rest, target, index + 1)
      }
    }
  }
}

fn find_complement(
  nums: List(Int),
  complement: Int,
  start_index: Int,
) -> Result(Int, Nil) {
  case
    list.index_map(nums, fn(num, i) {
      case num == complement {
        True -> Ok(i + start_index)
        False -> Error(Nil)
      }
    })
  {
    [Ok(index), ..] -> Ok(index)
    _ -> Error(Nil)
  }
}
