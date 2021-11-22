
const sha256=require("crypto-js/sha256")
const ecLib=require("elliptic").ec
const ec=new ecLib("secp256k1")
class Transaction{
    constructor(from,to,amount){
        this.from=from
        this.to=to
        this.amount=amount
       // this.timestamp=timestamp
    }
    transactionHash(){
        return sha256(this.from+this.to+this.amount).toString()
    }
    sign(key){
        this.signature=key.sign(this.transactionHash(),"base64").toDER("hex")
    }

    isValid(){
        const keyObj=ec.keyFromPublic(this.from,"hex")
        return keyObj.verify(this.transactionHash(),this.signature)
    }
}
class Block{
    constructor(transaction,previousHash){
        this.transaction=transaction
        this.previousHash=previousHash
        this.timestamp=Date.now()
        this.nonce=1
        this.hash=this.computerHash()
    }
    computerHash(){
        return sha256(JSON.stringify(this.transaction)+this.previousHash+this.nonce+this.timestamp).toString()
    }


    /*getAnswer(difficulty){
        let answer = ""
        for(let i=0;i<difficulty;i++){
            answer=answer + "0"
        }
       console.log(answer)
    }*/

    mine(difficulty){
        this.validDateBlockTransaction()
        while(true){
            this.hash=this.computerHash()
            if(this.hash.substring(0,difficulty)!=="000"){
                this.nonce++
                this.hash=this.computerHash()

            }else{
                break
            }
        }
        console.log("挖矿结束",this.hash)


    }

    validDateBlockTransaction(){
        for(let transaction of this.transaction){
            if(!transaction.isValid())
           console.log("invalid transaction in tansaction,发现交易异常")
           return false
        }
        return true
    }

}

//const block = new Block("转账","111")
//console.log(block)

class Chain{
  constructor(){
      this.chain=[this.bigBang()]
      this.transactionPool=[]
      this.mineReward=50
      this.difficulty=3

  }
  bigBang(){
      const genesisBlock=new Block("创世区块","")
      return genesisBlock
  }

  getLatestBlock(){
      return this.chain[this.chain.length-1]
  }

  addTransaction(transaction){
      if(!transaction.isValid()){
          throw Error("invalid transaction")
      }
      console.log("valid transaction")
      this.transactionPool.push(transaction)
  }
  //increse block
  addBlockToChain(newBlock){
      //find pre hash
      newBlock.previousHash=this.getLatestBlock().hash
      //newBlock.hash=newBlock.computerHash()
      newBlock.mine(this.difficulty)
      this.chain.push(newBlock)

  }
  mineTransactionPool(mineRewardAdress){
      const mineRewardTransaction=new Transaction("",mineRewardAdress,this.mineReward)
      this.transactionPool.push(mineRewardTransaction)
      const newBlock=new Block(this.transactionPool,this.getLatestBlock().hash)
      newBlock.mine(this.difficulty)
      this.chain.push(newBlock)
      this.transactionPool=[]
     

  }


  validdateChain(){
      if(this.chain.length===1){
          if(this.chain[0].hash===sha256(this.chain[0].computerHash())){
              return false
          }
          return true
      }
      for(let i=1;i<=this.chain.length-1;i++){
          const blockToValidate=this.chain[i]
          if(!blockToValidate.validDateBlockTransaction()){
              console.log("发现非法交易")
              return false
          }
          if(blockToValidate.hash!==blockToValidate.computerHash()){
              console.log("数据篡改")
              return false
          }
          const previousBlock=this.chain[i-1]
          if(blockToValidate.previousHash!==previousBlock.hash){
              console.log("前后区块连接断裂")
              return false
          }
      }
      return true
  }


}

const myChain=new Chain()






