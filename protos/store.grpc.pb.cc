// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: generated/store.proto

#include "store.pb.h"
#include "store.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace store {

static const char* StoreService_method_names[] = {
  "/store.StoreService/Authenticate",
  "/store.StoreService/RegisterUser",
  "/store.StoreService/GetProduct",
  "/store.StoreService/AddToCart",
  "/store.StoreService/Checkout",
};

std::unique_ptr< StoreService::Stub> StoreService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< StoreService::Stub> stub(new StoreService::Stub(channel, options));
  return stub;
}

StoreService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Authenticate_(StoreService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RegisterUser_(StoreService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetProduct_(StoreService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AddToCart_(StoreService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Checkout_(StoreService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status StoreService::Stub::Authenticate(::grpc::ClientContext* context, const ::store::AuthRequest& request, ::store::AuthResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::store::AuthRequest, ::store::AuthResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Authenticate_, context, request, response);
}

void StoreService::Stub::async::Authenticate(::grpc::ClientContext* context, const ::store::AuthRequest* request, ::store::AuthResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::store::AuthRequest, ::store::AuthResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Authenticate_, context, request, response, std::move(f));
}

void StoreService::Stub::async::Authenticate(::grpc::ClientContext* context, const ::store::AuthRequest* request, ::store::AuthResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Authenticate_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::store::AuthResponse>* StoreService::Stub::PrepareAsyncAuthenticateRaw(::grpc::ClientContext* context, const ::store::AuthRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::store::AuthResponse, ::store::AuthRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Authenticate_, context, request);
}

::grpc::ClientAsyncResponseReader< ::store::AuthResponse>* StoreService::Stub::AsyncAuthenticateRaw(::grpc::ClientContext* context, const ::store::AuthRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAuthenticateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status StoreService::Stub::RegisterUser(::grpc::ClientContext* context, const ::store::RegisterRequest& request, ::store::RegisterResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::store::RegisterRequest, ::store::RegisterResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_RegisterUser_, context, request, response);
}

void StoreService::Stub::async::RegisterUser(::grpc::ClientContext* context, const ::store::RegisterRequest* request, ::store::RegisterResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::store::RegisterRequest, ::store::RegisterResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RegisterUser_, context, request, response, std::move(f));
}

void StoreService::Stub::async::RegisterUser(::grpc::ClientContext* context, const ::store::RegisterRequest* request, ::store::RegisterResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RegisterUser_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::store::RegisterResponse>* StoreService::Stub::PrepareAsyncRegisterUserRaw(::grpc::ClientContext* context, const ::store::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::store::RegisterResponse, ::store::RegisterRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_RegisterUser_, context, request);
}

::grpc::ClientAsyncResponseReader< ::store::RegisterResponse>* StoreService::Stub::AsyncRegisterUserRaw(::grpc::ClientContext* context, const ::store::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRegisterUserRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status StoreService::Stub::GetProduct(::grpc::ClientContext* context, const ::store::ProductRequest& request, ::store::ProductResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::store::ProductRequest, ::store::ProductResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetProduct_, context, request, response);
}

void StoreService::Stub::async::GetProduct(::grpc::ClientContext* context, const ::store::ProductRequest* request, ::store::ProductResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::store::ProductRequest, ::store::ProductResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetProduct_, context, request, response, std::move(f));
}

void StoreService::Stub::async::GetProduct(::grpc::ClientContext* context, const ::store::ProductRequest* request, ::store::ProductResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetProduct_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::store::ProductResponse>* StoreService::Stub::PrepareAsyncGetProductRaw(::grpc::ClientContext* context, const ::store::ProductRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::store::ProductResponse, ::store::ProductRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetProduct_, context, request);
}

::grpc::ClientAsyncResponseReader< ::store::ProductResponse>* StoreService::Stub::AsyncGetProductRaw(::grpc::ClientContext* context, const ::store::ProductRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetProductRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status StoreService::Stub::AddToCart(::grpc::ClientContext* context, const ::store::AddToCartRequest& request, ::store::AddToCartResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::store::AddToCartRequest, ::store::AddToCartResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AddToCart_, context, request, response);
}

void StoreService::Stub::async::AddToCart(::grpc::ClientContext* context, const ::store::AddToCartRequest* request, ::store::AddToCartResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::store::AddToCartRequest, ::store::AddToCartResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddToCart_, context, request, response, std::move(f));
}

void StoreService::Stub::async::AddToCart(::grpc::ClientContext* context, const ::store::AddToCartRequest* request, ::store::AddToCartResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddToCart_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::store::AddToCartResponse>* StoreService::Stub::PrepareAsyncAddToCartRaw(::grpc::ClientContext* context, const ::store::AddToCartRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::store::AddToCartResponse, ::store::AddToCartRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AddToCart_, context, request);
}

::grpc::ClientAsyncResponseReader< ::store::AddToCartResponse>* StoreService::Stub::AsyncAddToCartRaw(::grpc::ClientContext* context, const ::store::AddToCartRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAddToCartRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status StoreService::Stub::Checkout(::grpc::ClientContext* context, const ::store::CheckoutRequest& request, ::store::CheckoutResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::store::CheckoutRequest, ::store::CheckoutResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Checkout_, context, request, response);
}

void StoreService::Stub::async::Checkout(::grpc::ClientContext* context, const ::store::CheckoutRequest* request, ::store::CheckoutResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::store::CheckoutRequest, ::store::CheckoutResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Checkout_, context, request, response, std::move(f));
}

void StoreService::Stub::async::Checkout(::grpc::ClientContext* context, const ::store::CheckoutRequest* request, ::store::CheckoutResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Checkout_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::store::CheckoutResponse>* StoreService::Stub::PrepareAsyncCheckoutRaw(::grpc::ClientContext* context, const ::store::CheckoutRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::store::CheckoutResponse, ::store::CheckoutRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Checkout_, context, request);
}

::grpc::ClientAsyncResponseReader< ::store::CheckoutResponse>* StoreService::Stub::AsyncCheckoutRaw(::grpc::ClientContext* context, const ::store::CheckoutRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCheckoutRaw(context, request, cq);
  result->StartCall();
  return result;
}

StoreService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StoreService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StoreService::Service, ::store::AuthRequest, ::store::AuthResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StoreService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::store::AuthRequest* req,
             ::store::AuthResponse* resp) {
               return service->Authenticate(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StoreService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StoreService::Service, ::store::RegisterRequest, ::store::RegisterResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StoreService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::store::RegisterRequest* req,
             ::store::RegisterResponse* resp) {
               return service->RegisterUser(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StoreService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StoreService::Service, ::store::ProductRequest, ::store::ProductResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StoreService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::store::ProductRequest* req,
             ::store::ProductResponse* resp) {
               return service->GetProduct(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StoreService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StoreService::Service, ::store::AddToCartRequest, ::store::AddToCartResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StoreService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::store::AddToCartRequest* req,
             ::store::AddToCartResponse* resp) {
               return service->AddToCart(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StoreService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StoreService::Service, ::store::CheckoutRequest, ::store::CheckoutResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StoreService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::store::CheckoutRequest* req,
             ::store::CheckoutResponse* resp) {
               return service->Checkout(ctx, req, resp);
             }, this)));
}

StoreService::Service::~Service() {
}

::grpc::Status StoreService::Service::Authenticate(::grpc::ServerContext* context, const ::store::AuthRequest* request, ::store::AuthResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status StoreService::Service::RegisterUser(::grpc::ServerContext* context, const ::store::RegisterRequest* request, ::store::RegisterResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status StoreService::Service::GetProduct(::grpc::ServerContext* context, const ::store::ProductRequest* request, ::store::ProductResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status StoreService::Service::AddToCart(::grpc::ServerContext* context, const ::store::AddToCartRequest* request, ::store::AddToCartResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status StoreService::Service::Checkout(::grpc::ServerContext* context, const ::store::CheckoutRequest* request, ::store::CheckoutResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace store

