"""
The Python implementation of the GRPC image client.

Modified from grpc/examples/python/helloworld/greeting_client.py.
"""

from __future__ import print_function

import logging
from io import BytesIO

from PIL import Image
import grpc
import image_pb2
import image_pb2_grpc


def run():
    # NOTE(gRPC Python Team): .close() is possible on a channel and should be
    # used in circumstances in which the with statement does not fit the needs
    # of the code.
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = image_pb2_grpc.GreeterStub(channel)
        response = stub.SayHello(image_pb2.HelloRequest(name='you'))
    message = response.message
    buf = BytesIO(response.image)
    buf.seek(0)
    image = Image.open(buf, formats=["JPEG"])
    print(f"Greeter client received: {message}")
    image.show()


if __name__ == '__main__':
    logging.basicConfig()
    run()
