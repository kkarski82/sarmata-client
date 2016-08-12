// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: asr_service.proto
// Original file comments:
// some code and comment are copied form:
// https://github.com/GoogleCloudPlatform/java-docs-samples/blob/master/speech/grpc/src/main/java/third_party/google/speech/v1/cloud-speech.proto
//
// grammar persistence options
// - per alive connection: user opens special channel to service to define grammars, grammars are kept as long as connection is alive
// - predefined per user on disk: service keep predefined grammar as files on disk, loads it at startup
// - auto-cache: all grammars are cached automatically using its hash as ID, max number of cached grammars and prune policy must be defined
//
// users account manipulation will be provided by different service
//
#ifndef GRPC_asr_5fservice_2eproto__INCLUDED
#define GRPC_asr_5fservice_2eproto__INCLUDED

#include "asr_service.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace sarmata {

class ASR GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // recognizes speech in stream using given grammar
    std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>> Recognize(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>>(RecognizeRaw(context));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>> AsyncRecognize(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>>(AsyncRecognizeRaw(context, cq, tag));
    }
    // defines user-persistent grammar 
    virtual ::grpc::Status DefineGrammar(::grpc::ClientContext* context, const ::sarmata::DefineGrammarRequest& request, ::sarmata::DefineGrammarRespone* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::sarmata::DefineGrammarRespone>> AsyncDefineGrammar(::grpc::ClientContext* context, const ::sarmata::DefineGrammarRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::sarmata::DefineGrammarRespone>>(AsyncDefineGrammarRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientReaderWriterInterface< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>* RecognizeRaw(::grpc::ClientContext* context) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>* AsyncRecognizeRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::sarmata::DefineGrammarRespone>* AsyncDefineGrammarRaw(::grpc::ClientContext* context, const ::sarmata::DefineGrammarRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientReaderWriter< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>> Recognize(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriter< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>>(RecognizeRaw(context));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>> AsyncRecognize(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>>(AsyncRecognizeRaw(context, cq, tag));
    }
    ::grpc::Status DefineGrammar(::grpc::ClientContext* context, const ::sarmata::DefineGrammarRequest& request, ::sarmata::DefineGrammarRespone* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::sarmata::DefineGrammarRespone>> AsyncDefineGrammar(::grpc::ClientContext* context, const ::sarmata::DefineGrammarRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::sarmata::DefineGrammarRespone>>(AsyncDefineGrammarRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientReaderWriter< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>* RecognizeRaw(::grpc::ClientContext* context) GRPC_OVERRIDE;
    ::grpc::ClientAsyncReaderWriter< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>* AsyncRecognizeRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::sarmata::DefineGrammarRespone>* AsyncDefineGrammarRaw(::grpc::ClientContext* context, const ::sarmata::DefineGrammarRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_Recognize_;
    const ::grpc::RpcMethod rpcmethod_DefineGrammar_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // recognizes speech in stream using given grammar
    virtual ::grpc::Status Recognize(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::sarmata::RecognizeResponse, ::sarmata::RecognizeRequest>* stream);
    // defines user-persistent grammar 
    virtual ::grpc::Status DefineGrammar(::grpc::ServerContext* context, const ::sarmata::DefineGrammarRequest* request, ::sarmata::DefineGrammarRespone* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Recognize : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Recognize() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Recognize() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Recognize(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::sarmata::RecognizeResponse, ::sarmata::RecognizeRequest>* stream) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRecognize(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::sarmata::RecognizeResponse, ::sarmata::RecognizeRequest>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_DefineGrammar : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_DefineGrammar() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_DefineGrammar() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DefineGrammar(::grpc::ServerContext* context, const ::sarmata::DefineGrammarRequest* request, ::sarmata::DefineGrammarRespone* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDefineGrammar(::grpc::ServerContext* context, ::sarmata::DefineGrammarRequest* request, ::grpc::ServerAsyncResponseWriter< ::sarmata::DefineGrammarRespone>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Recognize<WithAsyncMethod_DefineGrammar<Service > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_Recognize : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Recognize() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Recognize() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Recognize(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::sarmata::RecognizeResponse, ::sarmata::RecognizeRequest>* stream) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_DefineGrammar : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_DefineGrammar() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_DefineGrammar() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DefineGrammar(::grpc::ServerContext* context, const ::sarmata::DefineGrammarRequest* request, ::sarmata::DefineGrammarRespone* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
};

}  // namespace sarmata


#endif  // GRPC_asr_5fservice_2eproto__INCLUDED
