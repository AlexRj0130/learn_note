
/* 例：
 *   两个类命名为 Message 和 Folder，分别表示电子邮件消息和消息目录
 *     每个 Message 可以出现在多个 Folder 中
 *     任意给定的 Message 的内容只有一个副本（具有相同 Message 内容的 Message 对象共享存储空间）
 *   
 *   基本设计：
 *     为了记录 Message 位于哪些 Folder 中，每个 Message 都会保存一个它所在 Folder 的指针的 set
 *     每个 Folder 都保存一个它包含的 Message 的指针的 set
 *     Message 类会提供 save 和 remove 操作，来向一个给定 Folder 添加或删除一条 Message
 *     当我们拷贝一个 Message 时，副本和原对象将是不同的 Message 对象
 *     当我们销毁一个 Message 时，它将不复存在（必须从包含此消息的所有 Folder 中删除指向此 Message 的指针）
 *     当我们将一个 Message 对象赋予另一个 Message 对象时，
 *       左侧 Message 对象的内容会被右侧 Message 对象的内容替代   
 *       还必须更新 Folder 集合，从原来包含左侧 Message 的 Folder 中将它删除，并将它添加到包含右侧 Message 的 Folder 中
 */

