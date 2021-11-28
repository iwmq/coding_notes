"""
The Python implementation of the GRPC image.Greeter server.

Modified from grpc/examples/python/image/greet_server.py.
"""

from concurrent import futures
import logging
import sys
from io import BytesIO

from PIL import Image
import grpc
import image_pb2
import image_pb2_grpc


IMAGE_PATH = "/home/jay/house.jpg"


class Greeter(image_pb2_grpc.GreeterServicer):

    def SayHello(self, request, context):
        message = f"Hello, {request.name}! I am jay at ubuntu server."
        image = Image.open(IMAGE_PATH)
        buf = BytesIO()
        image.save(buf, format="JPEG")
        reply = image_pb2.HelloReply(
            message=message,
            image=buf.getvalue()
        )
        return reply


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    image_pb2_grpc.add_GreeterServicer_to_server(Greeter(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    server.wait_for_termination()


if __name__ == '__main__':
    logging.basicConfig()
    serve()
