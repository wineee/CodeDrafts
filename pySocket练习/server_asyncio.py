#  === TCP 服务端程序 server.py ， 异步支持多客户端 ===

# 导入socket 库
import asyncio,socket

IP = '127.0.0.1'
PORT = 50002
BUFLEN = 512

# 定义处理数据收发的回调
async def handle_echo(reader, writer):
    addr = writer.get_extra_info('peername')
    while True:
        data = await reader.read(100)
        if not data:
            print(f"客户端{addr}关闭了连接")
            writer.close()
            break
        message = data.decode()
        print(f'收到{addr}信息： {message}')
        writer.write(data)

loop = asyncio.get_event_loop()
coro = asyncio.start_server(handle_echo, IP, PORT, loop=loop)        

server = loop.run_until_complete(coro)

print('服务端启动成功，在{}端口等待客户端连接...'.format(server.sockets[0].getsockname()[1]))
# Serve requests until Ctrl+C is pressed
try:
    loop.run_forever()
except KeyboardInterrupt:
    pass

server.close()
loop.run_until_complete(server.wait_closed())
loop.close()