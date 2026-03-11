from fastapi import FastAPI
from pydantic import BaseModel

from llama_index.core import VectorStoreIndex, SimpleDirectoryReader, Settings
from llama_index.embeddings.huggingface import HuggingFaceEmbedding
from llama_index.llms.ollama import Ollama

app = FastAPI()

class Prompt(BaseModel):
    message: str


# 🔹 로컬 모델 설정 (중요)
Settings.embed_model = HuggingFaceEmbedding(model_name="BAAI/bge-small-en-v1.5")
Settings.llm = Ollama(model="llama3")


# 문서 로드
documents = SimpleDirectoryReader("./data_test").load_data()

# 인덱스 생성
index = VectorStoreIndex.from_documents(documents)

query_engine = index.as_query_engine()


@app.post("/npc")
async def npc_chat(prompt: Prompt):

    response = query_engine.query(prompt.message)

    return {
        "response": str(response)
    }