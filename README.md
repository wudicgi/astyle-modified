# AStyle 修改版本

## 所修改问题

当使用选项

```
indent=spaces=4
indent-after-parens
indent-continuation=2
```

对代码

```c
int ret = avfilter_graph_create_filter(&buffersrc_ctx, buffersrc, "in",
        args, NULL, filter_graph);

int (*enc_func_2)(AVCodecContext *, AVPacket *, const AVFrame *, int *) = (ifmt_ctx->streams[stream_index]->codecpar->codec_type ==
     AVMEDIA_TYPE_VIDEO) ? avcodec_encode_video2 : avcodec_encode_audio2;

ret = func(a, b, another_func(1, 2,
                3),
        c, d);
```

进行代码风格美化时，原版的 AStyle 会产生类似这样的输出:

```c
int ret = avfilter_graph_create_filter(&buffersrc_ctx, buffersrc, "in",
                args, NULL, filter_graph);

int (*enc_func_2)(AVCodecContext *, AVPacket *, const AVFrame *, int *) = (ifmt_ctx->streams[stream_index]->codecpar->codec_type ==
                AVMEDIA_TYPE_VIDEO) ? avcodec_encode_video2 : avcodec_encode_audio2;

ret = func(a, b, another_func(1, 2,
                        3),
                c, d);
```

它对代码中的后续行使用了 4 级缩进 (4 * 4 = 16 个空格)。但是根据 `indent-continuation=2` 选项设置，我们期望这些行应该只拥有 2 级缩进。

出现这个问题的原因在于，当遇到赋值运算符 '=' 时，由于指定了 `indent-continuation=2` 选项, AStyle 会为后续行添加 2 级缩进。而当继续处理遇到左括号 '(' 时，由于指定了 `indent-after-parens` 选项, AStyle 再次添加了 2 级缩进。于是后续行拥有了多余的 2 级缩进。

## 修改结果

修改后的版本可以在已经因为 '=' 添加了后续行缩进的情况下，不再因为其后出现的第一个 '(' 再添加缩进。

使用同样的选项，修改后版本所产生的输出类似于:

```c
int ret = avfilter_graph_create_filter(&buffersrc_ctx, buffersrc, "in",
        args, NULL, filter_graph);

int (*enc_func_2)(AVCodecContext *, AVPacket *, const AVFrame *, int *) = (ifmt_ctx->streams[stream_index]->codecpar->codec_type ==
        AVMEDIA_TYPE_VIDEO) ? avcodec_encode_video2 : avcodec_encode_audio2;

ret = func(a, b, another_func(1, 2,
                3),
        c, d);
```

## 修改的副作用

对于一些极端情况的代码，例如:

```c
int ret = func(a, b, another_func(1, 2,
3, 4, 5),
c, d)
/ 123;
```

原版 AStyle 能保留所有缩进等级，输出结果为:

```c
int ret = func(a, b, another_func(1, 2,
                        3, 4, 5),
                c, d)
        / 123;
```

而该修改版本的输出为:

```
int ret = func(a, b, another_func(1, 2,
                3, 4, 5),
        c, d)
        / 123;
```

最外层在缩进等级上没有与内层区分开来。

# AStyle 原版链接

AStyle 的官方项目地址为 [http://astyle.sourceforge.net/](http://astyle.sourceforge.net/)
