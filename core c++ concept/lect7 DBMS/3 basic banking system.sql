create database basic_banking_system ;

USE basic_banking_system ;

CREATE TABLE branch(
    branch_id VARCHAR(10) PRIMARY KEY,
    branch_city VARCHAR(50) NOT NULL,
    branch_name VARCHAR(50) NOT NULL
)

CREATE TABLE customer(
    id VARCHAR(50) PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    contact VARCHAR(10) NOT NULL,
    dob DATETIME NOT NULL,
    pan_number VARCHAR(10) NOT NULL,
    associated_branch_id VARCHAR(10) NOT NULL,
    
    FOREIGN KEY (associated_branch_id) REFERENCES branch(branch_id),

) ;

CREATE TABLE employee(
    employee_id VARCHAR(50) PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    salary INT NOT NULL,
    address VARCHAR(50) NOT NULL,
    associated_branch_id VARCHAR(10) NOT NULL,
    
    FOREIGN KEY (associated_branch_id) REFERENCES branch(branch_id),

) ;

CREATE TABLE account(
    account_number VARCHAR(15) PRIMARY KEY,
    balance INT NOT NULL,
    customer_id VARCHAR(50),

    FOREIGN KEY(customer_id) REFERENCES customer(id)
) ;

CREATE TABLE current_account(
    trnx_charge INT NOT NULL,
    overdraft INT NOT NULL,
    account_number VARCHAR(15),

    PRIMARY KEY(account_number) ,
    FOREIGN KEY (account_number) REFERENCES account(account_number)
) ;

CREATE TABLE savings_account(
    interet_rate INT NOT NULL,
    daily_withdraw_limit INT NOT NULL,
    account_number VARCHAR(15),

    PRIMARY KEY(account_number) ,
    FOREIGN KEY (account_number) REFERENCES account(account_number)
) ;

CREATE TABLE loan_account(
    interet_rate INT NOT NULL,
    loan_amount INT NOT NULL,
    account_number VARCHAR(15),
    customer_id VARCHAR(50),

    PRIMARY KEY(account_number) ,
    FOREIGN KEY (account_number) REFERENCES account(account_number)
    FOREIGN KEY (customer_id) REFERENCES customer(id)
) ;

CREATE TABLE transactions(
    transaction_number VARCHAR(50) PRIMARY KEY,
    date DATETIME NOT NULL,
    sender_account VARCHAR(15),
    reciver_account VARCHAR(15),

    FOREIGN KEY (sender_account) REFERENCES account(account_number) 
    FOREIGN KEY (reciver_account) REFERENCES account(account_number) 
)


INSERT INTO branch VALUES("0000000000","Indore","kalani nagar");



INSERT INTO customer VALUES("1","Akshat","6267366080",'2003-10-04',"LFTPK5756C","0000000000");

INSERT INTO customer VALUES("2","Garvit","6267366080",'2003-10-06',"LFTPK5758C","0000000000"),("3","Aastha","6267366080",'2006-09-13',"LFTPK6758C","0000000000");
