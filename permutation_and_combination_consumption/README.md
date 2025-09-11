这是一个本人自发的排列组合算法小总结

以下是文件结构：
PermutationCombinationSummary/  # 项目根目录
├── src/                        # 核心代码目录
│   ├── permutations/           # 排列问题模块
│   │   ├── no_repetition/      # 无重复元素的排列
│   │   │   ├── full_perm/      # 全排列
│   │   │   │   ├── basic_perm.h       # 基础全排列（无限制）
│   │   │   │   ├── fixed_position.h   # 带固定位置限制
│   │   │   │   └── order_constraint.h # 带顺序约束（如a必须在b前）
│   │   │   └── partial_perm/   # 部分排列（选k个元素）
│   │   │       ├── basic_partial.h    # 基础部分排列
│   │   │       └── adjacent_constraint.h # 带相邻/不相邻限制
│   │   └── with_repetition/    # 有重复元素的排列
│   │       ├── full_perm/      # 含重复元素的全排列
│   │       └── partial_perm/   # 含重复元素的部分排列
│   │
│   ├── combinations/           # 组合问题模块
│   │   ├── no_repetition/      # 无重复元素的组合
│   │   │   ├── basic_comb.h    # 基础组合（C(n,k)）
│   │   │   ├── quantity_limit.h # 带数量范围限制（至少/至多选k个）
│   │   │   └── group_comb/     # 分组组合
│   │   │       ├── unordered_group.h  # 组无顺序
│   │   │       └── ordered_group.h    # 组有顺序
│   │   └── with_repetition/    # 有重复元素的组合（可重复选取）
│   │       ├── unlimited.h     # 无限重复（无次数限制）
│   │       └── limited.h       # 有限重复（有最大次数限制）
│   │
│   └── common/                 # 公共工具模块
│       ├── utils.h             # 通用工具函数（如打印结果、去重）
│       └── types.h             # 公共数据类型（如结果集的类型定义）
│
├── tests/                      # 测试代码目录（与src结构对应）
│   ├── permutations_test/
│   ├── combinations_test/
│   └── CMakeLists.txt          # 测试模块的CMake配置
│
├── main.cpp                    # 主程序（调用不同模块的示例）
└── CMakeLists.txt              # 项目根CMake配置