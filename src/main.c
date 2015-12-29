/**
 * @describe: 基于 libehtp 的接口项目
 * @author: Jerry Yang(hy0kle@gmail.com)
 * @notice: 仅支持 *nix 系统
 * TODO
 * 1. 一期不使用内存池,先出一版看效果
 * 2. redis storage 应该也配置成主从,先不实现.
 * */
#include "util.h"
#include "init.h"

/** 全局变量 */
server_config_t   g_conf;
zlog_category_t  *g_zc;
ConnectionPool_T  mysql_master_pool;
ConnectionPool_T *mysql_slaves_pool;

int main(int argc, char *argv[])
{
    init();
    // 日志库开启了
    zlog_info(g_zc, "初始化成功");

    uint64_t max_keepalives = 60;
    evbase_t * evbase = event_base_new();
    evhtp_t  * htp    = evhtp_new(evbase, NULL);

    evhtp_set_max_keepalive_requests(htp, max_keepalives);

    // 注册路由
    evhtp_set_glob_cb(htp, "*", default_router, NULL);

    evhtp_bind_socket(htp, g_conf.ip, g_conf.port, g_conf.backlog);

    event_base_loop(evbase, 0);

    evhtp_unbind_socket(htp);
    evhtp_free(htp);
    event_base_free(evbase);

    // 清理 clean
    clean();
    return 0;
}

/* vim:set ft=c ts=4 sw=4 et fdm=marker: */

