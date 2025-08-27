import struct

def parse_cstyle_bytes(cstr: str) -> int:
    """
    把C风格八进制转义的字符串（例如 "\\367\\000\\000..."）
    转换成 Python 整数（uint64 小端解析）
    """
    # 先把 Python 字符串解码成真正的字节串
    # 'unicode_escape' 可以把 \000 \367 这些转义序列还原
    raw_bytes = cstr.encode('utf-8').decode('unicode_escape').encode('latin1')
    
    # 按照小端 uint64 解码
    val, = struct.unpack("<Q", raw_bytes[:8])  # 只取前8字节
    return val


# 示例
s = "\\367\\000\\000\\000\\000\\000\\000\\000"
print(parse_cstyle_bytes(s))  # 输出 247