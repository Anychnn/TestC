##DIR_DIFF设计方案

##### Patch文件结构设计方案

FileHead部分:

暂未储存任何信息，后续可以加上crc验证，版本号之类信息

FileInfo部分:

根据第一个读到的一个byte确定接下来的操作，目前1代表改名/移动, 2代表diff

1:改名/移动

oldPath长度(4byte) oldPath newPath长度(4byte) newPath

2:diff

oldPath长度(4 byte) oldPath newPath长度(4 byte) newPath patchSize(4 byte)

##### Diff步骤:

##### Patch步骤: