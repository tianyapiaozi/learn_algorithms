==重叠任务问题==
给定若干任及每个任务都是串行的无法同时进行两个时能够完成的最大数量的任务是多少？

伪代码
    J为任务集合
    while J 不为 do
        选取集合J可以完成的任务j
        从J中删除j及与j重叠的任务
        打印j