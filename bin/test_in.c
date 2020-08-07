void test(void) {
    int ret = avfilter_graph_create_filter(&buffersrc_ctx, buffersrc, "in",
            args, NULL, filter_graph);

    int (*enc_func)(AVCodecContext *, AVPacket *, const AVFrame *, int *) =
        (ifmt_ctx->streams[stream_index]->codecpar->codec_type ==
         AVMEDIA_TYPE_VIDEO) ? avcodec_encode_video2 : avcodec_encode_audio2;

    ret = func(a, b, another_func(1, 2,
                    3),
            c, d);
}

void more_test(void) {
    int ret = avfilter_graph_create_filter(&buffersrc_ctx, buffersrc, "in",
            args, NULL,
            filter_graph);

    int (*enc_func_1)(AVCodecContext *, AVPacket *, const AVFrame *, int *) =
        (ifmt_ctx->streams[stream_index]->codecpar->codec_type ==
         AVMEDIA_TYPE_VIDEO) ? avcodec_encode_video2 : avcodec_encode_audio2;

    int (*enc_func_2)(AVCodecContext *, AVPacket *, const AVFrame *, int *) = (ifmt_ctx->streams[stream_index]->codecpar->codec_type ==
         AVMEDIA_TYPE_VIDEO) ? avcodec_encode_video2 : avcodec_encode_audio2;

    int (*enc_func_3)(AVCodecContext *, AVPacket *, const AVFrame *, int *) = (ifmt_ctx->streams[stream_index]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
            ? avcodec_encode_video2 : avcodec_encode_audio2;

    int (*enc_func_4)(AVCodecContext *, AVPacket *, const AVFrame *, int *) =
            (ifmt_ctx->streams[stream_index]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
            ? avcodec_encode_video2
            : avcodec_encode_audio2;
}

static int init_filter(FilteringContext* fctx, AVCodecContext *dec_ctx,
        AVCodecContext *enc_ctx, const char *filter_spec)
{
    isLongVariable1 =
        foo1 ||
        foo2;

    isLongVariable2 = foo1 ||
        foo2;

    isLongVariable3 = foo1
        || foo2;

    isLongFunction(
        bar1,
        bar2);

    if (a < b
            || c > d)
        foo++;

    return 0;
}
