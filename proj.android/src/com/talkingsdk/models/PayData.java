package com.talkingsdk.models;

public class PayData {
	private String _myOrderId;
	private String _productId;
	private String _productName;
	// 成交价格
	private float  _productRealPrice;
	// 原价
	private float  _productIdealPrice;
	private int    _productCount;
	private String _description;
	public String getMyOrderId() {
		return _myOrderId;
	}
	public void setMyOrderId(String myOrderId) {
		this._myOrderId = myOrderId;
	}
	public String getProductId() {
		return _productId;
	}
	public void setProductId(String productId) {
		this._productId = productId;
	}
	public String getProductName() {
		return _productName;
	}
	public void setProductName(String productName) {
		this._productName = productName;
	}
	public float getProductRealPrice() {
		return _productRealPrice;
	}
	public void setProductRealPrice(float productRealPrice) {
		this._productRealPrice = productRealPrice;
	}
	public float getProductIdealPrice() {
		return _productIdealPrice;
	}
	public void setProductIdealPrice(float productIdealPrice) {
		this._productIdealPrice = productIdealPrice;
	}
	public int getProductCount() {
		return _productCount;
	}
	public void setProductCount(int productCount) {
		this._productCount = productCount;
	}
	public String getDescription() {
		return _description;
	}
	public void setDescription(String description) {
		this._description = description;
	}
}
