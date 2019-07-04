package com.study.threendk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.study.capplication.NDKTool;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    private Button btnAdd,btnSub,btnMul,btnDiv;
    private EditText inputA,inputB;
    private TextView tvResult;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        NDKTool ndk = new NDKTool();
//        String str = ndk.getStringFromNDK();
//        Log.i("jll", " str" + str);

        setupView();
        addListener();
    }

    private void addListener() {
        btnAdd.setOnClickListener(this);
        btnDiv.setOnClickListener(this);
        btnMul.setOnClickListener(this);
        btnSub.setOnClickListener(this);
    }

    private void setupView() {
        btnAdd=this.findViewById(R.id.add);
        btnDiv=this.findViewById(R.id.div);
        btnMul=this.findViewById(R.id.mul);
        btnSub=this.findViewById(R.id.sub);

        inputA=this.findViewById(R.id.inputa);
        inputB=this.findViewById(R.id.inputb);

        tvResult=this.findViewById(R.id.result);
    }


    @Override
    public void onClick(View v) {
        double result=0;
        String strA=inputA.getText().toString();
        String strB=inputB.getText().toString();
        int a=Integer.parseInt(strA);
        int b=Integer.parseInt(strB);
        switch (v.getId()){
            case R.id.add:
                result=NDKTool.add(a,b);
                NDKTool ndkTool =new NDKTool();
                ndkTool.callJavaStatticMethod();
                break;
            case R.id.div:
                result=NDKTool.div(a,b);
                break;
            case R.id.mul:
                result=NDKTool.mul(a,b);
                break;
            case R.id.sub:
                result=NDKTool.sub(a,b);
                break;
        }
        tvResult.setText(""+result);
    }
}
