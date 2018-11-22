pipeline {
  agent any
  stages {
      stage('Update remote source') {
        steps {
          sshagent(credentials: ['test-server-ssh-key']) {
              configFileProvider([configFile(fileId: 'test-server-ip', variable: 'TEST_SERVER_IP')]) {
                sh 'ssh `cat $TEST_SERVER_IP` -o StrictHostKeyChecking=no \'cd mfm-h-3.0-LoRa && git pull && git reset --hard && pio lib install lib/*/ \''
            }
          }
        }
      }
    stage('Test native') {
      steps {
        sshagent(credentials: ['test-server-ssh-key']) {
            configFileProvider([configFile(fileId: 'test-server-ip', variable: 'TEST_SERVER_IP')]) {
              sh 'ssh `cat $TEST_SERVER_IP` -o StrictHostKeyChecking=no \'cd mfm-h-3.0-LoRa && pio test -e native\''
          }
        }
      }
    }
    stage('Test UNO') {
      steps {
        sshagent(credentials: ['test-server-ssh-key']) {
            configFileProvider([configFile(fileId: 'test-server-ip', variable: 'TEST_SERVER_IP')]) {
              sh 'ssh `cat $TEST_SERVER_IP` -o StrictHostKeyChecking=no \'cd mfm-h-3.0-LoRa && pio test -e uno\''
          }
        }
      }
    }
  }
}
