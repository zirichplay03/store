// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: store.proto

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
namespace fitness {

static const char* FitnessService_method_names[] = {
  "/fitness.FitnessService/GetServices",
  "/fitness.FitnessService/LoginUser",
  "/fitness.FitnessService/RegisterUser",
  "/fitness.FitnessService/GetTrainers",
  "/fitness.FitnessService/GetTrainerSchedule",
  "/fitness.FitnessService/GetTrainerClients",
  "/fitness.FitnessService/GetContacts",
  "/fitness.FitnessService/GetPrices",
  "/fitness.FitnessService/BookTraining",
  "/fitness.FitnessService/AddBalance",
};

std::unique_ptr< FitnessService::Stub> FitnessService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< FitnessService::Stub> stub(new FitnessService::Stub(channel, options));
  return stub;
}

FitnessService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetServices_(FitnessService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_LoginUser_(FitnessService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RegisterUser_(FitnessService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetTrainers_(FitnessService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetTrainerSchedule_(FitnessService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetTrainerClients_(FitnessService_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetContacts_(FitnessService_method_names[6], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetPrices_(FitnessService_method_names[7], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_BookTraining_(FitnessService_method_names[8], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AddBalance_(FitnessService_method_names[9], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status FitnessService::Stub::GetServices(::grpc::ClientContext* context, const ::fitness::Empty& request, ::fitness::ServiceList* response) {
  return ::grpc::internal::BlockingUnaryCall< ::fitness::Empty, ::fitness::ServiceList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetServices_, context, request, response);
}

void FitnessService::Stub::async::GetServices(::grpc::ClientContext* context, const ::fitness::Empty* request, ::fitness::ServiceList* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::fitness::Empty, ::fitness::ServiceList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetServices_, context, request, response, std::move(f));
}

void FitnessService::Stub::async::GetServices(::grpc::ClientContext* context, const ::fitness::Empty* request, ::fitness::ServiceList* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetServices_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::fitness::ServiceList>* FitnessService::Stub::PrepareAsyncGetServicesRaw(::grpc::ClientContext* context, const ::fitness::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::fitness::ServiceList, ::fitness::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetServices_, context, request);
}

::grpc::ClientAsyncResponseReader< ::fitness::ServiceList>* FitnessService::Stub::AsyncGetServicesRaw(::grpc::ClientContext* context, const ::fitness::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetServicesRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FitnessService::Stub::LoginUser(::grpc::ClientContext* context, const ::fitness::LoginRequest& request, ::fitness::LoginResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::fitness::LoginRequest, ::fitness::LoginResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_LoginUser_, context, request, response);
}

void FitnessService::Stub::async::LoginUser(::grpc::ClientContext* context, const ::fitness::LoginRequest* request, ::fitness::LoginResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::fitness::LoginRequest, ::fitness::LoginResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_LoginUser_, context, request, response, std::move(f));
}

void FitnessService::Stub::async::LoginUser(::grpc::ClientContext* context, const ::fitness::LoginRequest* request, ::fitness::LoginResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_LoginUser_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::fitness::LoginResponse>* FitnessService::Stub::PrepareAsyncLoginUserRaw(::grpc::ClientContext* context, const ::fitness::LoginRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::fitness::LoginResponse, ::fitness::LoginRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_LoginUser_, context, request);
}

::grpc::ClientAsyncResponseReader< ::fitness::LoginResponse>* FitnessService::Stub::AsyncLoginUserRaw(::grpc::ClientContext* context, const ::fitness::LoginRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncLoginUserRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FitnessService::Stub::RegisterUser(::grpc::ClientContext* context, const ::fitness::RegisterRequest& request, ::fitness::RegisterResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::fitness::RegisterRequest, ::fitness::RegisterResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_RegisterUser_, context, request, response);
}

void FitnessService::Stub::async::RegisterUser(::grpc::ClientContext* context, const ::fitness::RegisterRequest* request, ::fitness::RegisterResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::fitness::RegisterRequest, ::fitness::RegisterResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RegisterUser_, context, request, response, std::move(f));
}

void FitnessService::Stub::async::RegisterUser(::grpc::ClientContext* context, const ::fitness::RegisterRequest* request, ::fitness::RegisterResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RegisterUser_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::fitness::RegisterResponse>* FitnessService::Stub::PrepareAsyncRegisterUserRaw(::grpc::ClientContext* context, const ::fitness::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::fitness::RegisterResponse, ::fitness::RegisterRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_RegisterUser_, context, request);
}

::grpc::ClientAsyncResponseReader< ::fitness::RegisterResponse>* FitnessService::Stub::AsyncRegisterUserRaw(::grpc::ClientContext* context, const ::fitness::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRegisterUserRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FitnessService::Stub::GetTrainers(::grpc::ClientContext* context, const ::fitness::Empty& request, ::fitness::TrainerList* response) {
  return ::grpc::internal::BlockingUnaryCall< ::fitness::Empty, ::fitness::TrainerList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetTrainers_, context, request, response);
}

void FitnessService::Stub::async::GetTrainers(::grpc::ClientContext* context, const ::fitness::Empty* request, ::fitness::TrainerList* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::fitness::Empty, ::fitness::TrainerList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetTrainers_, context, request, response, std::move(f));
}

void FitnessService::Stub::async::GetTrainers(::grpc::ClientContext* context, const ::fitness::Empty* request, ::fitness::TrainerList* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetTrainers_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::fitness::TrainerList>* FitnessService::Stub::PrepareAsyncGetTrainersRaw(::grpc::ClientContext* context, const ::fitness::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::fitness::TrainerList, ::fitness::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetTrainers_, context, request);
}

::grpc::ClientAsyncResponseReader< ::fitness::TrainerList>* FitnessService::Stub::AsyncGetTrainersRaw(::grpc::ClientContext* context, const ::fitness::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetTrainersRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FitnessService::Stub::GetTrainerSchedule(::grpc::ClientContext* context, const ::fitness::TrainerScheduleRequest& request, ::fitness::TrainerScheduleResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::fitness::TrainerScheduleRequest, ::fitness::TrainerScheduleResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetTrainerSchedule_, context, request, response);
}

void FitnessService::Stub::async::GetTrainerSchedule(::grpc::ClientContext* context, const ::fitness::TrainerScheduleRequest* request, ::fitness::TrainerScheduleResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::fitness::TrainerScheduleRequest, ::fitness::TrainerScheduleResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetTrainerSchedule_, context, request, response, std::move(f));
}

void FitnessService::Stub::async::GetTrainerSchedule(::grpc::ClientContext* context, const ::fitness::TrainerScheduleRequest* request, ::fitness::TrainerScheduleResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetTrainerSchedule_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::fitness::TrainerScheduleResponse>* FitnessService::Stub::PrepareAsyncGetTrainerScheduleRaw(::grpc::ClientContext* context, const ::fitness::TrainerScheduleRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::fitness::TrainerScheduleResponse, ::fitness::TrainerScheduleRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetTrainerSchedule_, context, request);
}

::grpc::ClientAsyncResponseReader< ::fitness::TrainerScheduleResponse>* FitnessService::Stub::AsyncGetTrainerScheduleRaw(::grpc::ClientContext* context, const ::fitness::TrainerScheduleRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetTrainerScheduleRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FitnessService::Stub::GetTrainerClients(::grpc::ClientContext* context, const ::fitness::TrainerClientsRequest& request, ::fitness::TrainerClientsResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::fitness::TrainerClientsRequest, ::fitness::TrainerClientsResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetTrainerClients_, context, request, response);
}

void FitnessService::Stub::async::GetTrainerClients(::grpc::ClientContext* context, const ::fitness::TrainerClientsRequest* request, ::fitness::TrainerClientsResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::fitness::TrainerClientsRequest, ::fitness::TrainerClientsResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetTrainerClients_, context, request, response, std::move(f));
}

void FitnessService::Stub::async::GetTrainerClients(::grpc::ClientContext* context, const ::fitness::TrainerClientsRequest* request, ::fitness::TrainerClientsResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetTrainerClients_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::fitness::TrainerClientsResponse>* FitnessService::Stub::PrepareAsyncGetTrainerClientsRaw(::grpc::ClientContext* context, const ::fitness::TrainerClientsRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::fitness::TrainerClientsResponse, ::fitness::TrainerClientsRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetTrainerClients_, context, request);
}

::grpc::ClientAsyncResponseReader< ::fitness::TrainerClientsResponse>* FitnessService::Stub::AsyncGetTrainerClientsRaw(::grpc::ClientContext* context, const ::fitness::TrainerClientsRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetTrainerClientsRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FitnessService::Stub::GetContacts(::grpc::ClientContext* context, const ::fitness::Empty& request, ::fitness::ContactList* response) {
  return ::grpc::internal::BlockingUnaryCall< ::fitness::Empty, ::fitness::ContactList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetContacts_, context, request, response);
}

void FitnessService::Stub::async::GetContacts(::grpc::ClientContext* context, const ::fitness::Empty* request, ::fitness::ContactList* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::fitness::Empty, ::fitness::ContactList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetContacts_, context, request, response, std::move(f));
}

void FitnessService::Stub::async::GetContacts(::grpc::ClientContext* context, const ::fitness::Empty* request, ::fitness::ContactList* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetContacts_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::fitness::ContactList>* FitnessService::Stub::PrepareAsyncGetContactsRaw(::grpc::ClientContext* context, const ::fitness::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::fitness::ContactList, ::fitness::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetContacts_, context, request);
}

::grpc::ClientAsyncResponseReader< ::fitness::ContactList>* FitnessService::Stub::AsyncGetContactsRaw(::grpc::ClientContext* context, const ::fitness::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetContactsRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FitnessService::Stub::GetPrices(::grpc::ClientContext* context, const ::fitness::Empty& request, ::fitness::PriceList* response) {
  return ::grpc::internal::BlockingUnaryCall< ::fitness::Empty, ::fitness::PriceList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetPrices_, context, request, response);
}

void FitnessService::Stub::async::GetPrices(::grpc::ClientContext* context, const ::fitness::Empty* request, ::fitness::PriceList* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::fitness::Empty, ::fitness::PriceList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetPrices_, context, request, response, std::move(f));
}

void FitnessService::Stub::async::GetPrices(::grpc::ClientContext* context, const ::fitness::Empty* request, ::fitness::PriceList* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetPrices_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::fitness::PriceList>* FitnessService::Stub::PrepareAsyncGetPricesRaw(::grpc::ClientContext* context, const ::fitness::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::fitness::PriceList, ::fitness::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetPrices_, context, request);
}

::grpc::ClientAsyncResponseReader< ::fitness::PriceList>* FitnessService::Stub::AsyncGetPricesRaw(::grpc::ClientContext* context, const ::fitness::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetPricesRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FitnessService::Stub::BookTraining(::grpc::ClientContext* context, const ::fitness::TrainingBookingRequest& request, ::fitness::TrainingBookingResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::fitness::TrainingBookingRequest, ::fitness::TrainingBookingResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_BookTraining_, context, request, response);
}

void FitnessService::Stub::async::BookTraining(::grpc::ClientContext* context, const ::fitness::TrainingBookingRequest* request, ::fitness::TrainingBookingResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::fitness::TrainingBookingRequest, ::fitness::TrainingBookingResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_BookTraining_, context, request, response, std::move(f));
}

void FitnessService::Stub::async::BookTraining(::grpc::ClientContext* context, const ::fitness::TrainingBookingRequest* request, ::fitness::TrainingBookingResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_BookTraining_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::fitness::TrainingBookingResponse>* FitnessService::Stub::PrepareAsyncBookTrainingRaw(::grpc::ClientContext* context, const ::fitness::TrainingBookingRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::fitness::TrainingBookingResponse, ::fitness::TrainingBookingRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_BookTraining_, context, request);
}

::grpc::ClientAsyncResponseReader< ::fitness::TrainingBookingResponse>* FitnessService::Stub::AsyncBookTrainingRaw(::grpc::ClientContext* context, const ::fitness::TrainingBookingRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncBookTrainingRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FitnessService::Stub::AddBalance(::grpc::ClientContext* context, const ::fitness::BalanceRequest& request, ::fitness::BalanceResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::fitness::BalanceRequest, ::fitness::BalanceResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AddBalance_, context, request, response);
}

void FitnessService::Stub::async::AddBalance(::grpc::ClientContext* context, const ::fitness::BalanceRequest* request, ::fitness::BalanceResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::fitness::BalanceRequest, ::fitness::BalanceResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddBalance_, context, request, response, std::move(f));
}

void FitnessService::Stub::async::AddBalance(::grpc::ClientContext* context, const ::fitness::BalanceRequest* request, ::fitness::BalanceResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddBalance_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::fitness::BalanceResponse>* FitnessService::Stub::PrepareAsyncAddBalanceRaw(::grpc::ClientContext* context, const ::fitness::BalanceRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::fitness::BalanceResponse, ::fitness::BalanceRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AddBalance_, context, request);
}

::grpc::ClientAsyncResponseReader< ::fitness::BalanceResponse>* FitnessService::Stub::AsyncAddBalanceRaw(::grpc::ClientContext* context, const ::fitness::BalanceRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAddBalanceRaw(context, request, cq);
  result->StartCall();
  return result;
}

FitnessService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FitnessService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FitnessService::Service, ::fitness::Empty, ::fitness::ServiceList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FitnessService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::fitness::Empty* req,
             ::fitness::ServiceList* resp) {
               return service->GetServices(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FitnessService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FitnessService::Service, ::fitness::LoginRequest, ::fitness::LoginResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FitnessService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::fitness::LoginRequest* req,
             ::fitness::LoginResponse* resp) {
               return service->LoginUser(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FitnessService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FitnessService::Service, ::fitness::RegisterRequest, ::fitness::RegisterResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FitnessService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::fitness::RegisterRequest* req,
             ::fitness::RegisterResponse* resp) {
               return service->RegisterUser(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FitnessService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FitnessService::Service, ::fitness::Empty, ::fitness::TrainerList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FitnessService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::fitness::Empty* req,
             ::fitness::TrainerList* resp) {
               return service->GetTrainers(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FitnessService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FitnessService::Service, ::fitness::TrainerScheduleRequest, ::fitness::TrainerScheduleResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FitnessService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::fitness::TrainerScheduleRequest* req,
             ::fitness::TrainerScheduleResponse* resp) {
               return service->GetTrainerSchedule(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FitnessService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FitnessService::Service, ::fitness::TrainerClientsRequest, ::fitness::TrainerClientsResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FitnessService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::fitness::TrainerClientsRequest* req,
             ::fitness::TrainerClientsResponse* resp) {
               return service->GetTrainerClients(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FitnessService_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FitnessService::Service, ::fitness::Empty, ::fitness::ContactList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FitnessService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::fitness::Empty* req,
             ::fitness::ContactList* resp) {
               return service->GetContacts(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FitnessService_method_names[7],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FitnessService::Service, ::fitness::Empty, ::fitness::PriceList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FitnessService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::fitness::Empty* req,
             ::fitness::PriceList* resp) {
               return service->GetPrices(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FitnessService_method_names[8],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FitnessService::Service, ::fitness::TrainingBookingRequest, ::fitness::TrainingBookingResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FitnessService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::fitness::TrainingBookingRequest* req,
             ::fitness::TrainingBookingResponse* resp) {
               return service->BookTraining(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FitnessService_method_names[9],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FitnessService::Service, ::fitness::BalanceRequest, ::fitness::BalanceResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FitnessService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::fitness::BalanceRequest* req,
             ::fitness::BalanceResponse* resp) {
               return service->AddBalance(ctx, req, resp);
             }, this)));
}

FitnessService::Service::~Service() {
}

::grpc::Status FitnessService::Service::GetServices(::grpc::ServerContext* context, const ::fitness::Empty* request, ::fitness::ServiceList* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FitnessService::Service::LoginUser(::grpc::ServerContext* context, const ::fitness::LoginRequest* request, ::fitness::LoginResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FitnessService::Service::RegisterUser(::grpc::ServerContext* context, const ::fitness::RegisterRequest* request, ::fitness::RegisterResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FitnessService::Service::GetTrainers(::grpc::ServerContext* context, const ::fitness::Empty* request, ::fitness::TrainerList* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FitnessService::Service::GetTrainerSchedule(::grpc::ServerContext* context, const ::fitness::TrainerScheduleRequest* request, ::fitness::TrainerScheduleResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FitnessService::Service::GetTrainerClients(::grpc::ServerContext* context, const ::fitness::TrainerClientsRequest* request, ::fitness::TrainerClientsResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FitnessService::Service::GetContacts(::grpc::ServerContext* context, const ::fitness::Empty* request, ::fitness::ContactList* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FitnessService::Service::GetPrices(::grpc::ServerContext* context, const ::fitness::Empty* request, ::fitness::PriceList* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FitnessService::Service::BookTraining(::grpc::ServerContext* context, const ::fitness::TrainingBookingRequest* request, ::fitness::TrainingBookingResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FitnessService::Service::AddBalance(::grpc::ServerContext* context, const ::fitness::BalanceRequest* request, ::fitness::BalanceResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace fitness

